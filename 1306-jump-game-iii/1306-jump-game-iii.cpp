class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;

        vis[start] = true;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(arr[curr] == 0) return true;

            int forward = curr + arr[curr];
            int backward = curr - arr[curr];

            if(forward < n && !vis[forward]){
                vis[forward] = true;
                q.push(forward);
            }

            if(backward >= 0 && !vis[backward]){
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};