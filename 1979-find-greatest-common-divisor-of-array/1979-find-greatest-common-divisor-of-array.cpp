class Solution {
public:
    int GCD(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;

        return gcd(a % b, b);
    }

    int findGCD(vector<int>& nums) {
        int high = INT_MIN;
        int low = INT_MAX;

        for(int i : nums){
            high = max(high, i);
            low = min(low, i);
        }

        return GCD(high, low);
    }
};