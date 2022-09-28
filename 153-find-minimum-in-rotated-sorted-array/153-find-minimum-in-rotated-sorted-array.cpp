class Solution {
public:
    int findMin(vector<int>& nums) {
        int n_elements = nums.size();
        
        if(n_elements == 1) {
            return nums[0];
        }
        
        
        int left = 0, right = n_elements - 1;
        
        if(nums[left] < nums[right]) {
            return nums[left];
        }
        
        while(left + 1 < right) {
            int mid = left + ((right - left) / 2);
            int mid_element = nums[mid];
            
            if(mid_element >= nums[left]) {
                left = mid;
            } else if(mid_element < nums[left]) {
                right = mid;
            }
            
        }
        
        if(nums[left] < nums[right]) {
            return nums[left];
        }
        return nums[right];
        
        
    }
};