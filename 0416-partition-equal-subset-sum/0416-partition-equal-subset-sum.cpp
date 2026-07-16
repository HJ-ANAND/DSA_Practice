class Solution {
public:
    bool solve(int n, int tar, vector<int> nums, vector<vector<int>> &dp){
        if(tar == 0) return true;
        if(n <= 0) return false;

        if(dp[n-1][tar] != -1) return dp[n-1][tar];

        bool take = false;
        if(nums[n-1] <= tar){
            take = solve(n-1, tar - nums[n-1], nums, dp);
        }

        bool skip = solve(n-1, tar, nums, dp);

        return dp[n-1][tar] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0) return false;
        int tar = total/2;

        vector<vector<int>> dp(n, vector<int> (tar+1, 0));

        if(nums[0] <= tar) dp[0][nums[0]] = true;
        
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= tar; j++){
                bool skip = dp[i-1][j];
                bool take = false;

                if(nums[i] <= j){
                    take = dp[i-1][j-nums[i]];
                }

                dp[i][j] = take || skip;
            }
        }

        return dp[n-1][tar];

        // return solve(n, tar, nums, dp);
    }
};