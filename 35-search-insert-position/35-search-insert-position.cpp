class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n_elements = nums.size();
        
        
        int left = 0, right = n_elements - 1;
        
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            
            int mid_element = nums[mid];

            if(target == mid_element){
                return mid;
            }
            
            if(target > mid_element) {
                left = mid + 1;
            }
            else if(target < mid_element) {
                right = mid - 1;
            }
            
        }
        
        
        
        return left;
        
    }
};