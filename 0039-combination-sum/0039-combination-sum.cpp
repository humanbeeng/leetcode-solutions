class Solution {
public:

    void helper(vector<int> &candidates, vector<vector<int>> &result, vector<int> &combination, int target, int i) {
        if(i >= candidates.size()) {
            if(target == 0) {
                result.push_back(combination);
            }
            return;
        }

        int curr_element = candidates[i];

        if(curr_element <= target) {
            // Choice 1: Pick. But since we can keep on picking the same element any n times, we stay here and
            // dont move to next element
            combination.push_back(curr_element);
            helper(candidates, result, combination, target - curr_element, i);
            // Revert the state to backtrack
            combination.pop_back();

            // Choice 2: Don't pick
            helper(candidates, result, combination, target, i + 1);

        } else {
            // Not picking
            helper(candidates, result, combination, target, i + 1);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> result;
       vector<int> combination;

       helper(candidates, result, combination, target, 0);

       return result;

    }
};