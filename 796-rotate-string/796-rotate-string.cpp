class Solution {
public:
    bool rotateString(string s, string goal) {
        int s_len = s.size();
        int goal_len = goal.length();
        
        if(s_len != goal_len){
            return false;
        }
        
        if(s == goal) {
            return true;
        } 
        
        string s_twice = s + s;
        
        return s_twice.find(goal) != string::npos;

    }
};