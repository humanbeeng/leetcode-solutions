class Solution {
public:
    
    void helper(vector<vector<int>> &result, vector<int> &combination, vector<int> &candidates, int target, int i) {
        
        if(target == 0 or i >= candidates.size()) {
            if(target == 0)
                result.push_back(combination);
            return;
        } 
        
            if(candidates[i] <= target) {
                
//          Choose to pick, but, not moving i, since we can pick curr_element unlimited times
                combination.push_back(candidates[i]);
                
                helper(result, combination, candidates, target - candidates[i], i);
                
                combination.pop_back();
                
//           Choose not to pick
                helper(result, combination, candidates, target, i + 1);
                
            } else {
                helper(result, combination, candidates, target, i + 1);
            }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        
        helper(result, combination, candidates, target, 0);
        
        return result;
    }
};