class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

        map<pair<int, int>, int> cnt;

        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans++;
            }
            else {
                int a = nums[i];
                int b = nums[i + 1];

                if (a > b)
                    swap(a, b);

                cnt[{a, b}]++;
            }
        }

        int best = 0;

        for (auto p : cnt) {
            best = max(best,  p.second);
        }

        return ans + best;
    }
};