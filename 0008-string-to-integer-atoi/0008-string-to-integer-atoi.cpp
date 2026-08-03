class Solution {
public:
    int myAtoi(string s) {
        int n = 0;
        bool neg = false;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(i != 0 && s[i-1] != ' ') break;
                else continue;
            } 
            else if(s[i] == '-' || s[i] == '+'){
                if(i != 0 && s[i-1] != ' ') break;
                else if(s[i] == '-'){
                    neg = true;
                }
            }
            else if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                int num = s[i] - '0';

                if((long) n*10 + num > INT_MAX && neg) return INT_MIN;
                else if((long) n*10 + num > INT_MAX) return INT_MAX; 
                
                n = n*10 + num;
            }else{
                break;
            }
        }

        if(neg) n = -n;

        return n;
    }
};