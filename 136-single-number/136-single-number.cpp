class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int curr_xor = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            curr_xor ^= nums[i];
        }
        
        return curr_xor;
        
    }
};