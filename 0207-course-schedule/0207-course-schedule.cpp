class Solution {
public:
    bool cycle(int s, vector<int> &vis, vector<int> &path, vector<vector<int>> &pre){
        vis[s] = true;
        path[s] = true;

        for(auto e : pre[s]){
            if(!vis[e]){
                if(cycle(e, vis, path, pre)) return true;
            }else if(path[e]){
                return true;
            }
        }

        path[s] = false;
        return false;
    }

    vector<vector<int>> solve(vector<vector<int>> gr, int n){
        vector<vector<int>> ans(n);;

        for(auto &e : gr){
            int u = e[0];
            int v = e[1];
            ans[v].push_back(u);
        }

        return ans;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj = solve(pre, n);
        vector<int> vis(n, false);
        vector<int> path(n ,false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(cycle(i, vis, path, adj)) return false;
            }
        }

        return true;
    }
};