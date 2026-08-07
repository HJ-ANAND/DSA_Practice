class Solution {
public:
    int n;
    int solve(vector<int> &stone, int i, int res, vector<int> &dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        res = max(res, stone[i] - solve(stone, i + 1, res, dp));
        if(i+1 < n)
        res = max(res, stone[i] + stone[i+1] - solve(stone, i + 2, res, dp));
        if(i+2 < n)
        res = max(res, stone[i] + stone[i+1] + stone[i+2] - solve(stone, i + 3, res, dp));

        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stone) {
        n = stone.size();
        vector<int> dp(n+1);

        // int ans = solve(stone, 0, INT_MIN, dp);

        for(int i = n-1; i >= 0; i--){
            dp[i] = stone[i] - dp[i+1];
            if(i+1 < n)
            dp[i] = max(dp[i], stone[i] + stone[i+1] - dp[i+2]);
            if(i+2 < n)
            dp[i] = max(dp[i], stone[i] + stone[i+1] + stone[i+2] - dp[i+3]);
        }

        int ans = dp[0];

        if(ans > 0) return "Alice";
        else if(ans == 0) return "Tie";

        return "Bob"; 
    }
};