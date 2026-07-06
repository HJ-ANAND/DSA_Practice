class Solution {
public:
    void BFS(vector<vector<int>> &isConnected, vector<bool> &vis, int s, int n){
        queue<int> q;
        q.push(s);
        vis[s] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i = 0; i < n; i++){
                if(isConnected[curr][i] && !vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;

        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            BFS(isConnected, vis, i, n);
            count++;
        }

        return count;
    }
};