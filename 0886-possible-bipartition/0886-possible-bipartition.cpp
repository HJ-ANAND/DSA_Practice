class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> edges, int n){
        vector<vector<int>> ans(n+1);;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            ans[u].push_back(v);
            ans[v].push_back(u);
        }

        return ans;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj = solve(dislikes, n);
        queue<int> q;
        vector<int> vis(n + 1, -1);

        for(int i = 0; i <= n; i++){
            if(vis[i] != -1) continue;

            q.push(i);
            vis[i] = 0;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                for(auto &e : adj[curr]){
                    if(vis[e] == -1){
                        q.push(e);
                        vis[e] = 1 - vis[curr];
                    }else if(vis[e] == vis[curr]) return false;
                }
            }
        }

        return true;
    }
};