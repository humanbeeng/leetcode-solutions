class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq_map;
        
        if(s.length() != t.length()) {
            return false;
        }
        
        for(char c: s) {
            freq_map[c]++;
        }
        
        for(char c: t) {
            freq_map[c]--;
            if(freq_map[c] < 0) {
                return false;
            }
        }
        
       
        return true;
    }
};