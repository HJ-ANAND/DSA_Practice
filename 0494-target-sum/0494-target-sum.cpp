class Solution {
public:
    int S;
    int solve(int i, int sum, vector<int> &nums, int tar, vector<vector<int>> &dp){
        if(i == nums.size()){
            if(sum == tar) return 1;
            return 0;
        } 

        if(dp[i][sum + S] != -1) return dp[i][sum + S];

        int add = solve(i+1, sum + nums[i], nums, tar, dp);
        int sub = solve(i+1, sum - nums[i], nums, tar, dp);

        return dp[i][sum + S] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        S = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n+1, vector<int> (2*S+1, -1));

        return solve(0, 0, nums, target, dp);
    }
};