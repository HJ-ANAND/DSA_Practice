class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>> edges, int n){
        vector<vector<int>> ans(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            ans[u].push_back(v);
            ans[v].push_back(u);
        }

        return ans;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> lis = solve(edges, n);

        vector<bool> vis(n, false);
        queue<int> q;

        vis[source] = true;
        q.push(source);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(curr == destination) return true;

            for(auto x : lis[curr]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push(x);
                }
            }
        }

        return false;
    }
};