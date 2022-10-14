class Solution {
public:
    void helper(vector<int> &candidates, vector<vector<int>> &result, vector<int> &combination, int target, int start) {
        
        if(target == 0 or start >= candidates.size()){
            if(target == 0)
                result.push_back(combination);
            return;
        } 
        
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target) {
                break;
            }
            if(i != start and candidates[i] == candidates[i - 1])
                continue;
            
            if(candidates[i] <= target) {
                combination.push_back(candidates[i]);
                helper(candidates, result, combination, target - candidates[i], i + 1);
                combination.pop_back();
            }
            
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