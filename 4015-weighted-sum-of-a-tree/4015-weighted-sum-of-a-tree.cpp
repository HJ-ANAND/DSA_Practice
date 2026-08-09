class Solution {
public:
    int h = 0;
    void dfs(vector<vector<int>> &child, vector<int> &dep, int node, int d){
        dep[node] = d;
        h = max(d, h);

        for(int &n : child[node]){
            dfs(child, dep, n, d+1);
        }
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> child(n);

        for(int i = 1; i < n; i++){
            child[parent[i]].push_back(i);
        }

        vector<int> dep(n);
        dfs(child, dep, 0, 1);

        long long ans = 0;

        for(int i = 0; i < nums.size(); i++){
            ans += 1LL * nums[i] * (h - dep[i] + 1);
        }

        return ans;
    }
};