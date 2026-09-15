class Solution {
public:
    int solve(int x, int y, int &m, int &n, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(x == 0 && y == 0) return grid[0][0];

        if(dp[x][y] != -1) return dp[x][y];

        int up = INT_MAX, left = INT_MAX;

        if(x > 0) left = solve(x-1, y, m, n, grid, dp);
        if(y > 0) up = solve(x, y-1, m, n, grid, dp);

        return dp[x][y] = grid[x][y] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, m, n, grid, dp);
    }
};