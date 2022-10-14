class Solution {
public:

    void generate(vector<int> &nums, vector<int> &subset, vector<vector<int>> &result, int i) {
        if(i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        generate(nums, subset, result, i + 1);
        
        subset.push_back(nums[i]);
        
        generate(nums, subset, result, i + 1);        
        
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n_nums = nums.size();
        
        vector<vector<int>> result;
        
        vector<int> subset;
        
        generate(nums, subset, result, 0);
        
        return result;
    }
};