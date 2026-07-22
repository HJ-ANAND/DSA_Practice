class Solution {
public:
    int solve(int i, vector<int> &nums, vector<int> &dp){
        if(i <= 0) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i-1] + solve(i-2, nums, dp);
        int skip = solve(i-1, nums, dp);

        return dp[i] = max(take, skip); 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);

        if(n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            int take = nums[i] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(take, skip);
        }

        return dp[n-1];
    }
};