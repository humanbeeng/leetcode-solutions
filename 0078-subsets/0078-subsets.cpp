class Solution {
public:

    void helper(vector<int> &nums, vector<int> &subset, vector<vector<int>> &result, int n) {
        if(n < 0) {
            result.push_back(subset);
            return;
        }
        
        subset.push_back(nums[n]);
        
        helper(nums, subset, result, n - 1);
        
        subset.pop_back();
        
        helper(nums, subset, result, n - 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n_nums = nums.size();
        
        vector<vector<int>> result;
        
        vector<int> subset;
        
        helper(nums, subset, result, n_nums - 1);
        
        return result;
    }
};