class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int pos_placeholder = 0;
        int neg_placeholder = 1;
        
        for(int element: nums) {
            if(element < 0) {
                result[neg_placeholder] = element;
                neg_placeholder += 2;
            } else {
                result[pos_placeholder] = element;
                pos_placeholder += 2;
            }
        }
        
        return result;
    }
};