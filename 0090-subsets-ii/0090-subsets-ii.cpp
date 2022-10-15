class Solution {
public:
    void generateSubsets(vector<int> &nums, vector<vector<int>> &result, vector<int> &subset, int start) {
        
        result.push_back(subset);
        
        for(int i = start; i < nums.size(); i++) {
            if(i > start and nums[i] == nums[i - 1])
                continue;
            
            subset.push_back(nums[i]);
            generateSubsets(nums, result, subset, i + 1);
            subset.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        
        generateSubsets(nums, result, subset, 0);
        
        return result;
    }
};