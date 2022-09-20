class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n_elements = nums.size();
        int left = 0, right = n_elements - 1;
        
        int p = left;
        
        while(p <= right) {
            
            if(nums[p] == 1) {
                p++;
            }
            else if(nums[p] == 0) {
                swap(nums[p++], nums[left++]);
            }
            else if(nums[p] == 2) {
                swap(nums[p], nums[right--]);
            }
            
        }
        
        
    }
};