class Solution {
public:
    long long const zero = 999;
    long long const one = 999999;
    long long const two = 999999999;
    long long const three = 999999999999;
    long long const four = 999999999999999;
    long long countCommas(long long n) {
        if(n < 1000) return 0;

        if(n < 1000000) return n - zero;

        if(n < 1000000000){
            n -= zero;
            n -= one;
            return zero + one + 2*n;
        } 

        if(n < 1000000000000){
            n -= zero;
            n -= one;
            n -= two;
            return zero*2 + one*2 + two*2 + 3*n;
        } 

        if(n < 1000000000000000){
            n -= zero;
            n -= one;
            n -= two;
            n -= three;
            return zero*3 + one*3 + two*3 + three*3 + 4*n;
        } 

        n -= zero;
        n -= one;
        n -= two;
        n -= three;
        n -= four;
        return zero*4 + one*4 + two*4 + three*4 + four*4 + 5*n;
    }
};