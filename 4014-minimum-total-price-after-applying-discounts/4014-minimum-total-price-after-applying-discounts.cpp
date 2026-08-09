class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& dis) {
        int n = prices.size();
        int m = dis.size();
        
        sort(prices.begin(), prices.end());
        sort(dis.begin(), dis.end());

        int i = n-1, j = m-1;
        double sum = 0;

        while(i >= 0 && j >= 0){
            sum += prices[i] * ((100.0 - dis[j])/100.0);
            i--;
            j--;
        }

        while(i >= 0){
            sum += prices[i--];
        }

        return sum;
    }
};