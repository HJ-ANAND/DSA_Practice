class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> &mat){
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n ,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }

        return ans;
    }

    void BFS(vector<vector<int>> adj, vector<bool> &vis, int s){
        queue<int> q;
        q.push(s);
        vis[s] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto &e : adj[curr]){
                if(!vis[e]){
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj = solve(isConnected);
        
        int n = isConnected.size();
        int count = 0;

        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                BFS(adj, vis, i);
                count++;
            }
        }

        return count;
    }
};