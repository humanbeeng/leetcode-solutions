class Solution {
public:
    void helper(vector<int> &candidates, vector<vector<int>> &result, vector<int> &combination, int target, int start) {
        
        if(target < 0) return;

        if(target == 0) {
            result.push_back(combination);
            return;
        }

        if(start >= candidates.size()) return;

        for(int i = start; i < candidates.size(); i++) {
            int curr_element = candidates[i];

            if(i > start and curr_element == candidates[i - 1]) continue;

            combination.push_back(curr_element);
            helper(candidates, result, combination, target - curr_element, i + 1);
            combination.pop_back();

        }    
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        
        vector<int> combination;
        
        sort(candidates.begin(), candidates.end());
        
        helper(candidates, result, combination, target, 0);
        
        return result;
    }
};