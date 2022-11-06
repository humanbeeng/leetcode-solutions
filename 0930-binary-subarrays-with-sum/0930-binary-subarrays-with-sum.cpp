class Solution {
public:
    
    int atMost(vector<int> &nums, int goal) {
        if(goal < 0) return 0;
        
        int start = 0, curr_sum = 0, n = nums.size(), n_subarrays = 0;
        
        for(int i = 0; i < n; i++) {
            int curr_element = nums[i];
            curr_sum += curr_element;
            
            while(curr_sum > goal) {
                curr_sum -= nums[start++];
            }
            
            n_subarrays += i - start + 1;
        }
        
        return n_subarrays;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};