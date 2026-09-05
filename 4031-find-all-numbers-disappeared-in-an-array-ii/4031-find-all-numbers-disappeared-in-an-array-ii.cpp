class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int l = lower;

        for (int x : nums) {
            if (x < l) {
                continue;
            }

            if (x > upper) {
                break;
            }

            if (x > l) {
                ans.push_back({l, x - 1});
            }

            l = x + 1;
        }

        if (l <= upper) {
            ans.push_back({l, upper});
        }

        return ans;
    }
};