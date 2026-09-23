class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int k = sum - x;
        int csum = 0;
        int i = 0;

        int len = INT_MIN;

        for(int j = 0; j < n; j++){
            csum += nums[j];

            while(csum > k && i <= j){
                csum -= nums[i];
                i++;
            }

            if(csum == k){
                len = max(len, j-i+1);
            } 
        }

        return (len == INT_MIN) ? -1 : n - len;
    }
};