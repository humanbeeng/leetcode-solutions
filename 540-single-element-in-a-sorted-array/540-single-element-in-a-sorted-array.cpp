class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n_elements = nums.size(); 
        int left = 0, right = n_elements - 2;
        
        
        if(n_elements == 1) {
            return nums[0];
        }
        
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            
            int mid_element = nums[mid];
            
            if(mid_element == nums[mid ^ 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            
            
        }
        
        return nums[left];
        
        
        
        
    }
};