class Solution {
public:
    int solve(int x, int y, int m, int n, vector<vector<int>> &dp){
        if(x == m-1 && y == n-1) return 1;

        if(dp[x][y] != -1) return dp[x][y];

        int right = 0, down = 0;

        if(x < m) right = solve(x+1, y, m, n, dp);
        if(y < n) down = solve(x, y+1, m, n, dp);

        return dp[x][y] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(0, 0, m, n, dp);
    }
};