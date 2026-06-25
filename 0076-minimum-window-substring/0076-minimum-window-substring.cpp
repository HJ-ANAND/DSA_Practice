class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int m = t.size();

        if(m > n) return "";

        for(char c : t) mpp[c]++;

        int i = 0, j = 0;
        int size = INT_MAX;
        int start = 0;

        int c = m;
        while(j < n){
            if(mpp[s[j]] > 0) c--;
            mpp[s[j]]--;

            while(c == 0){
                if(j-i+1 < size){
                    size = j-i+1;
                    start = i;
                } 
                mpp[s[i]]++;
                if(mpp[s[i]] > 0) c++;
                i++;
            }

            j++;
        }

        return (size == INT_MAX) ? "" : s.substr(start, size);
    }
};