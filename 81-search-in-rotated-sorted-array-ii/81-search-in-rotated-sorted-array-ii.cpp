class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            
            int mid_element = nums[mid];
            
            if(mid_element == target) {
                return true;
            }
            
            if(mid_element > nums[left]) {
                if(target >= nums[left] && target < mid_element) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            else if(mid_element < nums[left]) {
                if(target <= nums[right] && target > mid_element) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            
            else if(nums[left] == mid_element){
                left++;
            }
        }
        
        return false;
    }
};