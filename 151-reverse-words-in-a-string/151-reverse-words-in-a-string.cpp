class Solution {
public:
    string reverseWords(string str) {
        reverse(str.begin(), str.end());
        
        string result = "";
        string curr_substr = "";
        int s = -1, e = 0;
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            
            if(not iswspace(c)) {
                if(s == -1) {
                    s = i;
                }
                curr_substr += c;
                
            } else {
                if(s != -1) {
                    reverse(curr_substr.begin(), curr_substr.end());
                    result += curr_substr;
                    result.push_back(' ');
                    curr_substr = "";
                    s = -1;
                }
            }
        }
        
        reverse(curr_substr.begin(), curr_substr.end());
        result += curr_substr;
        
        if(result.back() == ' ') {
            result.pop_back();
        }

        
        return result;
        
    }
};