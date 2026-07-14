class Solution {
public:
    bool DFS(int s, vector<vector<int>>gr, vector<int> &vis, stack<int> &st, vector<int> &pv){
        vis[s] = true;
        pv[s] = 1;

        for(auto u : gr[s]){
            if(!vis[u]){
                if(DFS(u, gr, vis, st, pv)) return true;
            }
            else if(pv[u]) return true;
        }

        pv[s] = 0;
        st.push(s);
        return false;
    }

    vector<vector<int>> solve(vector<vector<int>> gr, int n){
        vector<vector<int>> ans(n);

        for(auto e : gr){
            int u = e[0];
            int v = e[1];
            ans[v].push_back(u);
        }

        return ans;
    }

    vector<int> findOrder(int n, vector<vector<int>>& gr) {
        vector<vector<int>> adj = solve(gr, n);
        stack<int> st;
        vector<int> vis(n, false);
        vector<int> pathVis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if (DFS(i, adj, vis, st, pathVis)) return {};
            } 
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};