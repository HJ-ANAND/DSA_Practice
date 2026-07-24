class Solution {
public:
    bool ispal(string s){
        int i = 0, j = s.size()-1;

        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int size = j-i+1;
                if(size){
                    if(ispal(s.substr(i, size))) count++;
                }
            }
        }

        return count;
    }
};