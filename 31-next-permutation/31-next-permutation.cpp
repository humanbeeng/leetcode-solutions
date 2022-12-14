class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n_nums = nums.size();
        int dip_idx = n_nums - 1;
        
        while(dip_idx - 1 >= 0) {
            if(nums[dip_idx] > nums[dip_idx - 1]) {
                break;
            }
            dip_idx--;
        }
        
        if(dip_idx == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        dip_idx--;
        
        int next_greater_idx = n_nums - 1;
        
        while(next_greater_idx > dip_idx) {
            if(nums[next_greater_idx] > nums[dip_idx]) {
                break;
            }
            next_greater_idx--;
        }
        
        swap(nums[next_greater_idx], nums[dip_idx]);
        
        reverse(nums.begin() + dip_idx + 1, nums.end());
        // sort(nums.begin() + dip_idx, nums.end());
        return;
    }
};