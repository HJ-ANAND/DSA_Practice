class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string fhf = "";
        string shf = "";

        for(int i = 0; i < n/2; i++){
            fhf += s[i];
        }

        sort(fhf.begin(), fhf.end());

        string ans = fhf;

        if(n % 2 == 1) ans += s[n/2];

        reverse(fhf.begin(), fhf.end());

        ans += fhf;

        return ans;
    }
};