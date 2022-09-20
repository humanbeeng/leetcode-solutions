class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int curr_majority_candidate = nums[0];
        
        int majority_freq = 0;
        
        for(int element: nums) {
            if(element == curr_majority_candidate) {
                majority_freq++;
            }
            else {
                majority_freq--;
                if(not majority_freq) {
                    curr_majority_candidate = element;
                    majority_freq = 1;
                }
            }
        }
        
        return curr_majority_candidate;
        
    }
};