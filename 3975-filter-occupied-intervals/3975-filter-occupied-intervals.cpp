class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &nums){
        int n = nums.size();
        vector<vector<int>> merged;

        merged.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            vector<int> &last = merged.back();

            if(nums[i][0] <= last[1] + 1){
                last[1] = max(last[1], nums[i][1]);
            }else{
                merged.push_back(nums[i]);
            }
        }

        return merged;
    }
    
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& nums, int start, int end) {
        if(nums.size() == 0) return {};
        sort(nums.begin(), nums.end());

        vector<vector<int>> merged = merge(nums);

        vector<vector<int>> ans;

        for(auto & i : merged){
            int s = i[0];
            int e = i[1];

            if(e < start || s > end){
                ans.push_back({s, e});
            }
            else if(s < start && end < e){
                ans.push_back({s, start - 1});
                ans.push_back({end + 1, e});
            }else {
                if(s < start) ans.push_back({s, start - 1});
                if(e > end) ans.push_back({end + 1, e});
            }
        }

        return ans;
    }
};