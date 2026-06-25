class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int i = 0, j = 0;
        int n = nums.size();
        int size = INT_MIN;

        while(j < n){
            int ch = nums[j];
            mpp[ch]++;


            while(i < n && mpp[ch] > k){
                mpp[nums[i]]--;
                i++;
            }

            size = max(size, j-i+1);
            j++;
        }

        return size;
    }
};