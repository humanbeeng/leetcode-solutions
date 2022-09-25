class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int back = nums[0];
        
        int n_elements = nums.size();
        
        int n_unique = 1;
        
        int swap_placeholder = 1;
        
        for(int i = 1; i < n_elements; i++) {
            if(back != nums[i]) {
                back = nums[i];
                swap(nums[i], nums[swap_placeholder]);
                swap_placeholder++; 
                n_unique++;
            }
        }
        
        return n_unique;
    }
};