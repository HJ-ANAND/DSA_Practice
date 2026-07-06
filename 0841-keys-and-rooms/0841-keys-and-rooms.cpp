class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto x : rooms[curr]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push(x);
                }
            }
        }

        for(auto i : vis){
            if(!i) return false;
        }

        return true;
    }
};