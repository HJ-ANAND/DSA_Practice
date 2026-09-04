class Solution {
public:
    const int M = 1e9 + 7;
    long long power(long long a ,long long b){
        long long ans = 1;
        a %= M;
        while(b){
            if(b % 2) ans = (ans * a) % M;
            a = (a * a) % M; 
            b /= 2;
        }   

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(long long i : nums){
            long long w = i % 10;
            long long d = i / 10;

            int s = log10(d) + 1;

            int p = s - w;

            long long x = d / (power(10, p));
            long long y = d % (power(10, p));

            ans = (ans + power(x, y))%M;
        }

        return ans;
    }
};