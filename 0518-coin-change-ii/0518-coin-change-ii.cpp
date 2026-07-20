class Solution {
public:
    int solve(int n, vector<int> coins, int am, vector<vector<int>> &dp){
        if(am == 0) return 1;
        if(n <= 0) return 0;

        if(dp[n-1][am] != -1) return dp[n-1][am];

        int skip = solve(n-1, coins, am, dp);
        int take = 0;
        if(coins[n-1] <= am){
            take = solve(n, coins, am - coins[n-1], dp);
        }

        return dp[n-1][am] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i <= amount; i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int skip = dp[i-1][j];
                int take = 0;
                if(coins[i] <= j){
                    take = dp[i][j - coins[i]];
                }

                dp[i][j] = 1LL * take + skip;
            }
        }

        return dp[n-1][amount];
    }
};