class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n_elements = nums.size();
        int left = 0, right = n_elements - 1;
        
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            int mid_element = nums[mid];
            
            if(mid_element == target) {
                return mid;
            }
            
            else if(mid_element >= nums[left]) {
                
                if(target >= nums[left] && target < mid_element) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
                
            }
            
            else if(mid_element < nums[left]) {
                
                if(target <= nums[right] && target > mid_element) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            
        }
        return -1;
    }
};