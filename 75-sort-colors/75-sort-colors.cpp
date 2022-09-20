class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n_elements = nums.size();
        int one_placeholder = 0, two_placeholder = n_elements - 1;
        
        int p = one_placeholder;
        
        while(p <= two_placeholder) {
            
            if(nums[p] == 1) {
                p++;
            }
            else if(nums[p] == 0) {
                swap(nums[p++], nums[one_placeholder++]);
            }
            else if(nums[p] == 2) {
                swap(nums[p], nums[two_placeholder--]);
            }
            
        }
        
        
    }
};