class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n > m) return false;

        vector<int> suf(m+1);
        int i = n-1;

        suf[m] = n;

        for(int j = m-1; j >= 0; j--){
            if(i >= 0 && s[i] == t[j])i--;
            suf[j] = i + 1;
        }

        i = 0;

        for(int j = 0; j < m && i < n; j++){
            if(s[i] == t[j])i++;
            else{
                if(suf[j+1] <= 1 + i)return true;
            }
        }
        
        return i == n;
    }
};