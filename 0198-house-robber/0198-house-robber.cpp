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

        if(n == 1) return nums[0];

        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int ans = max(first, second);

        for(int i = 2; i < n; i++){
            int take = nums[i] + first;
            int skip = second;

            ans = max(take, skip);

            first = second;
            second = ans;
        }

        return ans;
    }
};