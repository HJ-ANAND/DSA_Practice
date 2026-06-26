class Solution {
public:
    int solve(vector<int> &nums, int k){
        unordered_map<int, int> mpp;
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;

        while(j < n){
            int a = nums[j];
            mpp[a]++;

            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }

            ans += (j-i+1);
            j++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};