class Solution {
    public:
    
    void helper(int k, int target, vector<vector<int>> &result, vector<int> &combination, int curr_element) {
        

        if(k == 0) {
            if(target == 0)
                result.push_back(combination);
            return;
        }
        
        if(curr_element > 9) return;
        
        combination.push_back(curr_element);
        helper(k - 1, target - curr_element, result, combination, curr_element + 1);
        combination.pop_back();
        helper(k, target, result, combination, curr_element + 1);
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        
        helper(k, target, result, combination, 1);
        
        return result;
    }
};