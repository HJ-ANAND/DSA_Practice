class Solution {
public:
    int solve(string s, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 1;
        if(i == j) return 1;
        if(s[i] != s[j]) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(s, i+1, j-1, dp);
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                count += solve(s, i, j, dp);
            }
        }

        return count;
    }
};