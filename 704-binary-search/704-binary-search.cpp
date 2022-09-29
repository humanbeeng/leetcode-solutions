class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while(left < right) {
            int mid = left + ((right - left) / 2);
            
            int mid_element = nums[mid];
            
            if(mid_element == target) {
                return mid;
            }
            if(target > mid_element) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return nums[right] == target ? right : -1;
    }
};