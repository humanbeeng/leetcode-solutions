class Solution {
public:
    string largestOddNumber(string num) {
        string result = "";
        
        for(int i = num.size() - 1; i >= 0; i--) {
            char c = num[i];
            
            int n = c - '0';

            
            if(n % 2 == 1) {
                result += (num.substr(0, i + 1));
                break;
            }
        }
        return result;
    }
};