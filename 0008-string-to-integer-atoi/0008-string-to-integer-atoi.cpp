class Solution {
public:
  
    
    int myAtoi(string s) {
        long result = 0;
        int i = 0, sign = 1;
        
        int len = s.size();
        
        while(i < len and s[i] == ' ') {
            i++;
        }
        
        if(s[i] == '+' or s[i] == '-') {
            if(s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        while(i < len and isdigit(s[i])) {
            int digit = (s[i] - '0') * sign;
            result = (result * 10) + digit;
            
            if(sign == 1 and (result >= INT_MAX))
                return INT_MAX;
            if(sign == -1 and result <= INT_MIN) 
                return INT_MIN;
            
            i++;
        }
        
        return result;
    }
};