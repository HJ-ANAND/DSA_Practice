class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            int c = 0, s = 0;
            for(int j = i; j < n; j++){
                s++;
                if(nums[j] == target) c++;
                if(2*c > s) count++;
            }
        }

        return count;
    }
};