class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        
        for(int element: nums) {
            result ^= element;
        }
        
        return result;
    }
};