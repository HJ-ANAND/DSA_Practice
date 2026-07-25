class Solution {
public:
    int maxProduct(int n) {
        if(n < 10) return n;
        int mx = INT_MIN;
        int smx = INT_MIN;

        while(n > 0){
            int rem = n % 10;
            if(rem > mx){
                smx = mx;
                mx = rem;
            } 
            else if(rem <= mx && rem >= smx) smx = rem;
            n /= 10;
        }

        return mx * smx;
    }
};