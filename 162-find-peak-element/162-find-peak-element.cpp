class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n_elements = nums.size();
        
        int left = 0, right = n_elements - 1;
        
        while(left + 1 < right) {
            int mid = left + ((right - left) / 2);
            
            int mid_element = nums[mid];
            
            if(mid_element > nums[mid + 1] && mid_element > nums[mid - 1]) {
                return mid;
            }
            
            else if(nums[mid + 1] >= nums[mid - 1]) {
                left = mid;
            }
            
            else if(nums[mid - 1] > nums[mid + 1]) {
                right = mid;
            } 
            
        }
        
        if(nums[left] > nums[right]) {
            return left;
        }
        
        return right;
        
    }
};