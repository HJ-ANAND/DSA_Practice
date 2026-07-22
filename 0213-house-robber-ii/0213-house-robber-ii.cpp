class Solution {
public:
    int solve(int i, int st, vector<int> &nums, vector<int> &dp){
        if(i < st) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i-2, st, nums, dp);
        int skip = solve(i-1, st, nums, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);

        int one = solve(n-2, 0, nums, dp);
        int two = solve(n-1, 1, nums, dp2);

        return max(one, two);
    }
};