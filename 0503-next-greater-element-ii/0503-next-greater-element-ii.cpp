class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n_nums = nums.size();
        nums.resize(n_nums * 2);
        
        vector<int> ngr;
        stack<int> s;
        
        for(int i = n_nums; i < (2 * n_nums); i++) {
            // from the end of nums
            nums[i] = nums[i - n_nums];
            
        }
        
        for(int i = n_nums; i >= 0; i--) {
            s.push(nums[i]);
        }
        
        for(int i = n_nums - 1; i >= 0; i--) {
            int curr_element = nums[i];
            
            if(s.empty()) {
                ngr.push_back(-1);
            } else {
                if(s.top() > curr_element) {
                    ngr.push_back(s.top());
                } else {
                    while(not s.empty() and s.top() <= curr_element) {
                    s.pop();
                    }
            
                    if(s.empty()) {
                        ngr.push_back(-1);
                    }
                    else if(s.top() > curr_element) {
                        ngr.push_back(s.top());
                    }
                }
                
            }
            
            s.push(curr_element);
        }
        reverse(ngr.begin(), ngr.end());
        
        return ngr;
        
    }
};