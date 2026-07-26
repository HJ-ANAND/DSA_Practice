class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        map<int, pair<int, int>> mpp;

        for(auto &x : series1){
            mpp[x[0]] = {0, 0};
        }

        for(auto &x : series2){
            mpp[x[0]] = {0, 0};
        }

        for(auto &x : series1){
            mpp[x[0]].first = x[1];
        }

        for(auto &x : series2){
            mpp[x[0]].second = x[1];
        }

        int next1 = 0, next2 = 0;

        for(auto it = mpp.rbegin(); it != mpp.rend(); it++){
            if(it->second.first == 0)it->second.first = next1;
            else next1 = it->second.first;

            if(it->second.second == 0)it->second.second = next2;
            else next2 = it->second.second;
        }

        vector<vector<int>> ans;

        for(auto &x : mpp){
            ans.push_back({x.first, x.second.first + x.second.second});
        }

        return ans;
    }
};