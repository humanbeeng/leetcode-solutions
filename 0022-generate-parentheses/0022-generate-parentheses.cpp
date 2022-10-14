class Solution {
public:
    const char closed_parentheses = ')';
    const char opened_parentheses = '(';
    
    void helper(vector<string> &result, string parens, int opened_left, int closed_left) {
        if(opened_left == 0 and closed_left == 0) {
            // No more generation is possible
            result.push_back(parens);
            return;
        }
        if(opened_left > 0) {
            parens.push_back(opened_parentheses);
            helper(result, parens, opened_left - 1, closed_left);
            parens.pop_back();
            
            //or
            // helper(result, parens + opened_parentheses, opened_left - 1, closed_left)
        }
        if(closed_left > opened_left) {
            // as soon as there are more opened_parentheses than closed, we attempt to put 
            // closed_parentheses to balance it out
            
            parens.push_back(closed_parentheses);
            helper(result, parens, opened_left, closed_left - 1);
            parens.pop_back();
            
            // or 
            // helper(result, parens + closed_parentheses, opened_left, closed_left - 1)
        }
    }
    
    vector<string> generateParenthesis(int n) {
       vector<string> result;
       helper(result, "", n, n); 
       return result;
    }
};

