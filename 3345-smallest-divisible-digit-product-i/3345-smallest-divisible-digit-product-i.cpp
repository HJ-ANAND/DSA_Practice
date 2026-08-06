class Solution {
public:
    int smallestNumber(int n, int t) {
        int pro = 1;
        int st = n;
        int i = 10;


        while(i--){
            while(n > 0){
                pro *= (n % 10);
                n /= 10;
            }

            cout << st << endl;

            if(pro % t == 0) return st;
            st++;
            n = st;
            pro = 1;
        }

        return -1;
    }
};