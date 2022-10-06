class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int n_strings = strs.size();
        
        sort(strs.begin(), strs.end());
        
        string a = strs[0];
        string b = strs[n_strings - 1];
        
        for(int i = 0; i < a.size(); i++) {
            if(i < a.size() && i < b.size() && a[i] == b[i]) {
                result += a[i];
            } else {
                return result;
            }
        }
        
        return result;
    }
};