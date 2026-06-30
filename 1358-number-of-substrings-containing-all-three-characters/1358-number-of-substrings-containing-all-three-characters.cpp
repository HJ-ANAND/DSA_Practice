class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;

        int ans = 0;

        vector<int> f(3);

        for(int j = 0; j < n; j++){
            int c = s[j];

            f[s[j] - 'a']++;

            while(f[0] && f[1] && f[2]){
                ans += (n-j);

                f[s[i] - 'a']--;
                i++;
            }
        }

        return ans;
    }
};