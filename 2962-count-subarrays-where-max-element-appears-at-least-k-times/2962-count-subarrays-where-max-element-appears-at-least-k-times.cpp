class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();

        int mx = INT_MIN;
        for(int i : nums) mx = max(mx, i);

        long long ans = 0;
        long long count = 0;

        while(j < n){
            if(nums[j] == mx) count++;

            while(count >= k){
                ans += n-j;
                if(nums[i] == mx) count--;
                i++;
            }

            j++;
        }

        return ans;
    }
};