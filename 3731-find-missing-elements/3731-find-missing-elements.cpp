class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        vector<bool> present(101, false);

        for(int i : nums){
            mn = min(i, mn);
            mx = max(i, mx);

            present[i] = true;
        }

        vector<int> ans;

        for(int i = mn; i <= mx; i++){
            if(!present[i]) ans.push_back(i);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};