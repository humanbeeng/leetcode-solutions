class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &result, vector<int> &combination, int start) {
        
        result.push_back(combination);
        
        for(int i = start; i < nums.size(); i++) {
            int curr_element = nums[i];
            if(i > start and nums[i - 1] == curr_element) continue;
            
            combination.push_back(curr_element);
            helper(nums, result, combination, i + 1);
            combination.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        vector<int> combination;
        
        helper(nums, result, combination, 0);
        
        return result;
    }
};