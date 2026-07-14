class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> gr, int n){
        vector<vector<int>> ans(n);;

        for(auto &e : gr){
            int u = e[0];
            int v = e[1];
            ans[v].push_back(u);
        }

        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj = solve(pre, n);
        unordered_map<int, int> mpp;

        for(auto e : pre){
            mpp[e[0]]++;
        }

        for(int i = 0; i < n; i++){
            if(!mpp.count(i)) mpp[i] = 0;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(!mpp[i]) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto e : adj[curr]){
                mpp[e]--;
                if(!mpp[e]) q.push(e);
            }
        }

        for(auto it : mpp) if(it.second > 0) return {};
        return ans;
    }
};