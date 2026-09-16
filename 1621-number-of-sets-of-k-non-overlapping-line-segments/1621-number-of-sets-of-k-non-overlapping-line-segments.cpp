class Solution {
public:
    const int M = 1e9+7;
    int dp[1001][1001];
    int solve(int i, int n, int k, vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(i >= n) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        long long skip = solve(i+1, n, k, dp)%M;
        long long take = 0;

        for(int j = i+1; j < n; j++){
            take += solve(j, n, k-1, dp)%M;
        }

        return dp[i][k] = skip + take;
    }

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};