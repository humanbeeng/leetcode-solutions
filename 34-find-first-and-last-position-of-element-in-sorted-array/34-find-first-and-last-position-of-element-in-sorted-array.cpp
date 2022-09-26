class Solution {
    
private :
    const int NOT_FOUND = -1;
public:
    
    int findFirstOccurrence(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        int first_occurring_idx = NOT_FOUND;
        
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            int mid_element = nums[mid];
            
            if(mid_element == target) {
                first_occurring_idx = mid;
                right = mid - 1;
            }
            else if(target > mid_element) {
                left = mid + 1;
            }
            else if(target < mid_element) {
                right = mid - 1;
            }
        }
        
        
        return first_occurring_idx;
    }
    
    
    int findLastOccurrence(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        int last_occurring_idx = NOT_FOUND;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            int mid_element = nums[mid];
           
            if(mid_element == target) {
                last_occurring_idx = mid;
                left = mid + 1;
            } else if(target > mid_element) {
                left = mid + 1;
            } else if(target < mid_element) {
                right = mid - 1;
            }
        }
        
        return last_occurring_idx;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_occurrence = findFirstOccurrence(nums, target);
        
        if(first_occurrence == NOT_FOUND) {
            vector<int> result = {NOT_FOUND, NOT_FOUND};
            return result;
        }
        
        int last_occurrence = findLastOccurrence(nums, target);
        
        vector<int> result = {first_occurrence, last_occurrence};
        return result;
    }
};