class Solution {
public:
    int solve(int st, string &s, vector<int> &dp){
        if(st == s.size()) return 1;
        if(s[st] == '0') return 0;

        if(dp[st] != -1) return dp[st];

        int ans = solve(st + 1, s, dp);

        if (st + 1 < s.size()) {
            int n = stoi(s.substr(st, 2));

            if (n <= 26) {
                ans += solve(st + 2, s, dp);
            }
        }

        return dp[st] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n+1, -1);

        return solve(0, s, dp);
    }
};