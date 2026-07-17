class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;

        vector<bool> vis(amount + 1, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        int count = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int sum = q.front();
                q.pop();

                if (sum == amount)
                    return count;

                for (int x : coins) {
                    long long nextSum = 1LL * sum + x;

                    if (nextSum <= amount && !vis[nextSum]) {
                        vis[nextSum] = true;
                        q.push(nextSum);
                    }
                }
            }
            count++;
        }

        return -1;
    }
};