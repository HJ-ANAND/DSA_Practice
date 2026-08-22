class Solution {
public:
    int Sum(int n){
        int ans = 0;

        while(n > 0){
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }

    int Mul(int n){
        int ans = 1;

        while(n > 0){
            ans *= n % 10;
            n /= 10;
        }

        return ans;
    }

    bool checkDivisibility(int n) {
        int sum = Sum(n);
        int pro = Mul(n);

        cout << sum << ", " << pro << endl;

        return n % (sum + pro) == 0;
    }
};