class Solution {
public:
    vector<int> solve(int n){
        vector<int> f;

        for(int i = 2; i *i <= n; i++){
            while(n % i == 0){
                f.push_back(i);
                n /= i;
            }
        }

        if(n > 1) f.push_back(n);

        return f;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> pf;

        for(int i : nums){
            pf[i] = solve(i);
        }

        unordered_map<int, int> prime_freq;

        int l = 0, r = 0;
        int ans = 0;

        while(r < n){
            for(int f: pf[nums[r]]) prime_freq[f]++;

            if(prime_freq.size() <= k) ans = max(ans, r-l+1);
            else{
                while(l <= r && prime_freq.size() > k){
                    for(int f : pf[nums[l]]){
                        prime_freq[f]--;
                        if(prime_freq[f] == 0) prime_freq.erase(f);
                    }
                    l++;
                }

                ans = max(ans, r-l+1);
            }
            r++;
        }

        return ans;
    }
};