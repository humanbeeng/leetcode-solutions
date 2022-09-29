class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n_elements = nums.size(); 
        int left = 0, right = n_elements - 1;
        
        
        if(n_elements == 1) {
            return nums[0];
        }
        
        while(left + 1 < right) {
            int mid = left + ((right - left) / 2);
            int mid_element = nums[mid];
            
            if(mid_element != nums[mid - 1] && mid_element != nums[mid + 1]) {
                return mid_element;
            }
            
            if((mid % 2 == 0)) {
                if(nums[mid] == nums[mid + 1])
                    left = mid + 1;
                else 
                    right = mid - 1;
            } else {
                if(nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else 
                    right = mid - 1;
            }
            
        }
        if(nums[left] == nums[left ^ 1]) {
            return nums[right];
        }
        
        return nums[left];
        
        
    }
};