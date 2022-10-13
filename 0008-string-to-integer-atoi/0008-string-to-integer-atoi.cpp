class Solution {
public:
    int updateSign(char c) {
        if(c == '-') {
            return -1;
        }
        return 1;   
    }
    
    int myAtoi(string s) {
//         long result = 0;
//         int i = 0, sign = 1;
        
//         int len = s.length();
        
//         while(i < len and iswspace(s[i])) {
//             i++;
//         }
        
//         sign = updateSign(s[i]);

        
//         while(i < len and isdigit(s[i])) {
//             int digit = (s[i] - '0') * sign;
//             result = (result * 10) + digit;
//             if(sign == 1 and (result >= INT_MAX))
//                 return INT_MAX;
//             if(sign == -1 and result <= INT_MIN) 
//                 return INT_MIN;
            
//             i++;
//         }
        
//         return result;
               long res=0;
        int i=0;
        int sign=1;
		
        while(i<s.size()&&s[i]==' ')i++;  //ignore leading white space
        
        if(s[i]=='-'||s[i]=='+')          //check if number positve or negative
        {
            sign=s[i]=='-'?-1:1;
            i++;
        }
        // now iterate across digits if any
		// should only be in range 0-9
        while(i<s.length()&&(s[i]>='0'&&s[i]<='9'))  //traverse string till nondigit not found or string ends
        {
            int digit=(s[i]-'0')*sign;
            res=res*10+digit; 
            if(sign==1 && (res>INT_MAX)) return INT_MAX; //check for overflow
            if(sign==-1 &&(res<INT_MIN)) return INT_MIN; //check for underflow
            
// update res
            i++;
        }
    
    return res;
    }
};