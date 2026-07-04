class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, odd = 0;
        int i = 0, m = 0;

        for(int j = 0; j < n; j++){
            if(nums[j] % 2 != 0) odd++;

            while(odd > k){
                if(nums[i] % 2 != 0) odd--;
                i++;
                m = i;
            }

            if(odd == k){
                while(nums[m] % 2 == 0) m++;
                ans += (m - i + 1);
            }
        }

        return ans;
    }
};