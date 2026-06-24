class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a.find(b) != string::npos) return 1;
        string newA = a;
        int count = 1;

        while(newA.size() < b.size()){
            newA += a;
            count++;
            if(newA.find(b) != string::npos) return count;
        }

        newA += a;
        count++;
        if(newA.find(b) != string::npos) return count;

        return -1;
    }
};