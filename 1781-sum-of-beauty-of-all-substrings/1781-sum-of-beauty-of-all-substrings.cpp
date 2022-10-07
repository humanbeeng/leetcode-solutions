class Solution {
public:
    int beautySum(string s) {
      
        
        int result = 0;
        int s_len = s.length();
        

        
        for(int i = 0; i < s_len; i++) {
            
            int freq[26] = {};
            
            for(int j = i; j < s_len; j++) {
                
                char c = s[j];
                int idx = c - 'a';
                freq[idx]++;
                int max_freq = INT_MIN, min_freq = INT_MAX;
                
                for(int k = 0; k < 26; k++) {
                    if(freq[k] == 0) {
                        continue;
                    }    
                    
                    max_freq = max(max_freq, freq[k]);
                    min_freq = min(min_freq, freq[k]);
                }
                
                result += (max_freq - min_freq);
                
                
                
            }
        }
        
        return result;
        
        
    }
};