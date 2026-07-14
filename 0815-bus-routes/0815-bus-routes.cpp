class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        int n = routes.size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            for(auto x : routes[i]) mpp[x].push_back(i);
        }

        if (!mpp.count(source) || !mpp.count(target)) return -1;

        vector<int> vis(n, false);
        queue<int> q;

        for(auto it : mpp[source]){
            q.push(it);
            vis[it] = true;
        } 
        vis[mpp[source][0]] = true;
        int count = 1;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();
                for(auto x : routes[curr]){
                    if(x == target) return count;
                    vector<int> temp = mpp[x];
                    for(auto i : temp){
                        if(!vis[i]){
                            vis[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
            count++;
        }

        return -1;
    }
};