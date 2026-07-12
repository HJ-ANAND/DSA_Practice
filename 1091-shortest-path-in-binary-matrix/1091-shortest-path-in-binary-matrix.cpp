class Solution {
public:
    vector<int> nrr = {0, 0, 1, -1, 1, -1, 1, -1};
    vector<int> ncc = {1, -1, 0, 0, 1, -1, -1, 1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(grid[0][0]) return -1;

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        queue<pair<int, int>> q;

        vis[0][0] = true;
        q.push({0, 0});
        int count = 1;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<int, int> curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                if(r == row-1 && c == col-1 && !grid[r][c]) return count;

                for(int i = 0; i < 8; i++){
                    int nr = r + nrr[i];
                    int nc = c + ncc[i];

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && !vis[nr][nc] && !grid[nr][nc]){
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            count++;
        } 

        return -1;
    }
};