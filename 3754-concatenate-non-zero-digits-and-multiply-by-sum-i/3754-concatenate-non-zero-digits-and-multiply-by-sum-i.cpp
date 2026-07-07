class Solution {
public:
    long long sumAndMultiply(int n) {
        if(!n) return n;
        long long sum = 0;

        string res;

        for(char c : to_string(n)){
            if(c != '0'){
                res += c;
                sum += (c - '0');
            }
        }

        int ans = stoi(res);

        return ans * sum;
    }
};