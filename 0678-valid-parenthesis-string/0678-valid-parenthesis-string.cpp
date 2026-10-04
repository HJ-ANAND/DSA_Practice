class Solution {
public:
    bool solve(int i, int open, string &s, int &n, vector<vector<int>> &dp){
        if(i == n){
            return open == 0;
        }

        if(dp[i][open] != -1) return dp[i][open];

        bool isValid = false;

        if(s[i] == '*'){
            isValid |= solve(i+1, open+1, s, n, dp);
            isValid |= solve(i+1, open, s, n, dp);
            if(open > 0){
                isValid |= solve(i+1, open-1, s, n, dp);
            }
        }else if(s[i] == '(') isValid = solve(i+1, open+1, s, n, dp);
        else{
            if(open > 0) isValid |= solve(i+1, open-1, s, n, dp);
        }

        return dp[i][open] = isValid;
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return solve(0, 0, s, n, dp); 
    }
};