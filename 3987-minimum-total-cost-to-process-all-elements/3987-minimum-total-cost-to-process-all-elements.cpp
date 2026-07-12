class Solution {
public:
    const long long M = 1000000007;
    int minimumCost(vector<int>& nums, int k) {
        long long cost = 0;
        long long times = 1;
        long long copy = k;

        for(int i : nums){
            if(copy < i){
                long long need = i - copy;
                long long ops = (need + k - 1) / k;
                
                __int128 term = (__int128)ops * (2 * times + ops - 1) / 2;
                cost = (cost + (long long)(term % M)) % M;
                
                times += ops;
                copy += ops * 1LL * k;
            } 
            copy -= i;
        }

        return cost % M;
    }
};