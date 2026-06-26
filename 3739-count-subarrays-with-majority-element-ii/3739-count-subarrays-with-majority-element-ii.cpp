class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int sum = 0;
        long long ans = 0;
        int var = 0;

        for(int i : nums){
            if(i == target){
                sum += mpp[var];
                var += 1;
            }else {
                var -= 1;
                sum -= mpp[var];
            }

            mpp[var] += 1;
            ans += sum;
        }

        return ans;
    }
};