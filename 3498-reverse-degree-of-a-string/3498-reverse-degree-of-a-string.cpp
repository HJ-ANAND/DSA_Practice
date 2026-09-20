class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int idx = 1;

        for(int c : s){
            int n = c - 'a';
            int rn = 26 - n;

            sum += (rn * idx);
            idx++;
        }

        return sum;
    }
};