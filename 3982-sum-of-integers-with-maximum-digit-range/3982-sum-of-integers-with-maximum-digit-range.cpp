class Solution {
public:
    int diff(int n){
        int temp = n;
        int mx = INT_MIN;
        int mn = INT_MAX;

        while(n > 0){
            int rem = n % 10;
            mx = max(mx, rem);
            n /= 10;
        }

        while(temp > 0){
            int rem = temp % 10;
            mn = min(mn, rem);
            temp /= 10;
        }

        return mx - mn;
    }
    
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        vector<int> alldiff;

        for(int i : nums){
            alldiff.push_back(diff(i));
        }

        int mx = INT_MIN;

        for(int i : alldiff) mx = max(mx, i);

        int sum = 0;

        for(int i = 0; i < n; i++){
            if(alldiff[i] == mx) sum += nums[i];
        }

        return sum;
    }
};