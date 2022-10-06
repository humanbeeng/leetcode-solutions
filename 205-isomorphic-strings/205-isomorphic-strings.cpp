class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, char> mp_s;
        unordered_map<char, char> mp_t;
        
        for(int i = 0; i < s.size(); i++) {
            char s_char = s[i];
            char t_char = t[i];
            
            if(mp_s[s_char] == 0 && mp_t[t_char] == 0) {
                mp_s[s_char] = t_char;
                mp_t[t_char] = s_char;
                continue;
            }
            
            if(s_char != mp_t[t_char] || t_char != mp_s[s_char]) {
                return false;
            }
            
        }
        
        return true;
        
    }
};