class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;
        queue<int> q;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            mpp[arr[i]].push_back(i);
        }

        vis[0] = true;
        q.push(0);
        int step = 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                int idx = q.front();
                q.pop();

                if(idx == n-1) return step;
                
                int r = idx + 1;
                int l = idx - 1;

                if(l >= 0 && !vis[l]){
                    vis[l] = true;
                    q.push(l);
                }

                if(r < n && !vis[r]){
                    vis[r] = true;
                    q.push(r);
                }

                for(auto &it : mpp[arr[idx]]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push(it);
                    }
                }

                mpp.erase(arr[idx]);
            }

            step++;
        }

        return -1;
    }
};