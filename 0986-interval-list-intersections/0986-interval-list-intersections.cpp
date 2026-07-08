class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int n = firstList.size();
        int m = secondList.size();

        int i = 0, j = 0;

        while(i < n && j < m){
            int si = firstList[i][0];
            int ei = firstList[i][1];
            int sj = secondList[j][0];
            int ej = secondList[j][1];

            int st = max(si, sj);
            int end = min(ei, ej);

            if(st <= end) ans.push_back({st, end});

            if(ei < ej) i++;
            else j++;
        }

        return ans;
    }
};