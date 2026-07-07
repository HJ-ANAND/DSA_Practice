class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        queue<int> q;

        for(int i = 0; i < n; i++){
            if(vis[i] != -1) continue;

            q.push(i);
            vis[i] = 0;

            while(!q.empty()){

                int curr = q.front();
                q.pop();
                
                for(auto &e : graph[curr]){
                    if(vis[e] == -1){
                        q.push(e);
                        vis[e] = 1 - vis[curr];
                    }
                    else if(vis[e] == vis[curr]) return false;
                }
            }
            
        }
        

        return true;
    }
};