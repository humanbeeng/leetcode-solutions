class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> m(n);
        int max_len = 0, start = 0, end = 0;
        
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(m.find(c) != m.end()) {
                start = max(start, m[c] + 1);
            }
            int curr_len = i - start + 1;
            max_len = max(max_len, curr_len);
            m[c] = i;
        }
        
        return max_len;
    }
};