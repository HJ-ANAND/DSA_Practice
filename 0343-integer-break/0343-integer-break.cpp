class Solution {
public:
    int t[59];
    int solve(int n){
        if(n == 1) return 1;
        int ans = INT_MIN;

        if (t[n] != -1) return t[n];

        for(int i = 1; i <= n-1; i++){
            int pro = i * max(n-i, solve(n-i));
            ans = max(ans, pro);
        }

        return t[n] = ans;
    }

    int integerBreak(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};