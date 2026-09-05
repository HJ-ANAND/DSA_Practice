class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);

        int small = nums[n-1];
        for(int i = n-1; i >= 0; i--){
            small = min(small, nums[i]);
            prefix[i] = max(prefix[i], small);
        }

        int big = INT_MIN; 
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            big = max(big, nums[i]);
            int num = big - prefix[i];
            if(num <= k) ans = min(ans, i);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};