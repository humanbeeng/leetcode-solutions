class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n_elements = nums.size();
        if(n_elements == 0 || n_elements == 1) {
            return n_elements;
        } 
    
        int max_len = 1;
        unordered_set<int> s;
        
        for(int element: nums) {
            s.insert(element);
        }
        
        for(int element: nums) {
            if(not s.count(element - 1)) {
                int seq_element = element;
                int curr_len = 1;
                
                while(s.count(seq_element + 1)) {
                    curr_len++;
                    seq_element++;
                    max_len = max(max_len, curr_len);
                }
            }
        }
        
        return max_len;
    }
};