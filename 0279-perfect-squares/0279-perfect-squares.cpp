class Solution {
public:
    int solve(int n, vector<int> &sq, int i, vector<vector<int>> &dp){
        if(n == 0) return 0;

        if (i == sq.size() || n < 0)
            return 1e9;

        if (dp[i][n] != -1)
            return dp[i][n];

        int take = 1e9;

        if (sq[i] <= n) {
            take = 1 + solve(n - sq[i], sq, i, dp);
        }

        int skip = solve(n, sq, i + 1, dp);

        return dp[i][n] = min(take, skip);
    }

    int numSquares(int n) {
        vector<int> sq;

        for(int i = 1; i * i <= n; i++){
            sq.push_back(i*i);
        }

        vector<vector<int>> dp(sq.size(), vector<int>(n+1, -1));

        return solve(n, sq, 0, dp);
    }
};