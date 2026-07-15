class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);
        while(sumEven!=0){
            int r = sumOdd % sumEven;
            sumOdd = sumEven;
            sumEven = r;
        }
        return sumOdd;
    }
};