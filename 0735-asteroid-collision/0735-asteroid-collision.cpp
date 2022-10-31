class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        

        
        for(int curr_size : asteroids) {
            
            if(curr_size > 0) {
                s.push_back(curr_size);
            } else {
                while(not s.empty() and s.back() > 0 and abs(curr_size) > s.back()) {    
                    s.pop_back();
                }
//                 Destruction stopped when either there's no asteroid left to destroy or 
//                 we have encountered asteroid of same direction (-, left). In that case, 
//                 curr_asteroid will just remain in the state forever.
//                 OR we have encountered asteroid of same size and opposite dir(right)
                    
                if(s.empty() or s.back() < 0) 
                    s.push_back(curr_size);
                else if(s.back() > 0 and s.back() == abs(curr_size)) 
                    s.pop_back();

            }
            
        }
        
        
        
        return s;
    }
};