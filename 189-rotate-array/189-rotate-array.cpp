class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n_elements = nums.size();
        
        k = k % n_elements;
        
        if(n_elements == 1) {
            return;
        }
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin() + k);
        
        reverse(nums.begin() + k, nums.end());
        
        
    }
};