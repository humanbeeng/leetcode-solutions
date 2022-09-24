class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for(int i = 0; i + 1 < nums.size(); i++) {
            
            if((i > 0) && nums[i - 1] == nums[i]) {
                continue;
            }
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            int curr_element = nums[i];
            
            while(left < right) {
                int curr_triplet_sum = curr_element + nums[left] + nums[right];
                
                if(curr_triplet_sum == 0) {
                    vector<int> triplet = {curr_element, nums[left], nums[right]};
                    result.push_back(triplet);
                    left++;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else if(curr_triplet_sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return result;
        
    }
};