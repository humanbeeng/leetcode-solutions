class Solution {
public:
    const char closed_parentheses = ')';
    const char opened_parentheses = '(';

    void helper(vector<string> &result, string parens, int opened_remain, int closed_remain) {
        if(opened_remain == 0 and closed_remain == 0) {
            // there are no more parentheses to add
            result.push_back(parens);
            return;
        }

        if(opened_remain > 0) {
            helper(result, parens + opened_parentheses, opened_remain - 1, closed_remain);
        }

        if(closed_remain > opened_remain) {
            helper(result, parens + closed_parentheses, opened_remain, closed_remain - 1);
        }

    }
    vector<string> generateParenthesis(int n) {
       vector<string> result;
       helper(result, "", n, n); 
       return result;
    }
};

