class Solution {
public:
    vector<vector<int>> makeadj(vector<vector<int>> &edges, int n){
        vector<vector<int>> ans(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            ans[u].push_back(v);
        }

        return ans;
    }

    void solve(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &sus, int st){
        vis[st] = true;
        sus.push_back(st);

        for(auto &i : adj[st]){
            if(!vis[i]) solve(adj, vis, sus, i);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj = makeadj(invocations, n);

        vector<int> sus;
        vector<bool> vis(n, false);

        solve(adj, vis, sus, k);

        vector<int> ans;

        bool found = false;

        for(auto &e : invocations){
            int from  = e[0];
            int to = e[1];

            if(!vis[from] && vis[to]){
                found = true;
                break;
            }
        }

        if(found){
            for(int i = 0; i < n; i++) ans.push_back(i);
        }else{
            for(int i = 0; i < n; i++){
                if(!vis[i]) ans.push_back(i);
            }
        }

        return ans;
    }
};