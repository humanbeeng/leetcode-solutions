class Solution {
public:
    void generateSubsets(vector<int> &nums, vector<vector<int>> &result, vector<int> &subset, int start) {
        
        if(start >= nums.size()) {
            result.push_back(subset);
            return;
        }
        
        subset.push_back(nums[start]);
        generateSubsets(nums, result, subset, start + 1);
        subset.pop_back();
        
        while((start + 1) < nums.size() and nums[start] == nums[start + 1]) 
            start++;
        
        generateSubsets(nums, result, subset, start + 1);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        
        generateSubsets(nums, result, subset, 0);
        
        return result;
    }
};