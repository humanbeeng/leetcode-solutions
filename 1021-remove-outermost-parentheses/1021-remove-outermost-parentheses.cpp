class Solution {
public:
    string removeOuterParentheses(string s) {
        int n_open = 0, n_closed = 0;
        bool is_opened = false;
        string result = "";

        const char open_bracket = '(', closed_bracket = ')';
        
        for(char c: s) {
            if(c == open_bracket) {
                if(n_open > 0) {
                    result.push_back(c);
                }
                n_open++;
            }
            else if(c == closed_bracket) {
                if(n_open > 1) {
                    result.push_back(c);
                }
                n_open--;
            }
        }
        
        return result;
        
    }
};