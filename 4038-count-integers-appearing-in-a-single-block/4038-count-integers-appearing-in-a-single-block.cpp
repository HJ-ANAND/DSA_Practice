class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        set<int> seen;
        set<int> bad;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {

                if (seen.count(nums[i])) {
                    bad.insert(nums[i]);
                }

                seen.insert(nums[i]);
            }
        }

        return seen.size() - bad.size();
    }
};