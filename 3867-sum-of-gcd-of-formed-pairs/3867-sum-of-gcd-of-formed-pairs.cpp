class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        vector<int> preGCD;

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            preGCD.push_back(gcd(nums[i], mx));
        }

        sort(preGCD.begin(), preGCD.end());

        n = preGCD.size();
        long long sum = 0;

        for(int i = 0; i < n/2; i++){
            if(i == n-1-i) continue;
            sum += gcd(preGCD[i], preGCD[n-1-i]);
        }

        return sum;
    }
};