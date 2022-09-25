class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n_elements = nums.size();
        int placeholder = 0;
        
        for(int i = 0; i < n_elements; i++) { 
            if(nums[i] != 0) {
                swap(nums[i], nums[placeholder++]);
            }
            
        }
    }
};