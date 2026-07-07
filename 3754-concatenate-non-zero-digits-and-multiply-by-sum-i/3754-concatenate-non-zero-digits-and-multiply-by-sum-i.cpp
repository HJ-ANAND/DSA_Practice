class Solution {
public:
    long long sumAndMultiply(int n) {
        if(!n) return n;
        long long temp = n;
        long long sum = 0;

        while(temp > 0){
            int rem = temp % 10;
            if(rem) sum += rem;
            temp /= 10;
        }

        string res;

        for(char c : to_string(n)){
            if(c != '0'){
                res += c;
            }
        }

        int ans = stoi(res);

        return ans * sum;
    }
};