class Solution {
public:
    vector<int> LPS(string pat){
        int n = pat.size();
        vector<int> ans(n);
        int len = 0;
        int i = 1;

        while(i < n){
            if(pat[i] == pat[len]){
                len++;
                ans[i] = len;
                i++;
            }else{
                if(len) len = ans[len-1];
                else i++;
            }
        }

        return ans;
    }

    bool kmp(string str, string pat){
        int n = str.size();
        int m = pat.size();

        vector<int> lps = LPS(pat);

        int i = 0, j = 0;

        while(i < n && j < m){
            if(str[i] == pat[j]){
                i++;
                j++;
                if(j == m) return true;
            }else{
                if(j) j = lps[j-1];
                else i++;
            }
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for(string s : patterns){
            if(kmp(word, s)) count++;
        }

        return count;
    }
};