class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    void bfs(vector<vector<char>> &grid, int r, int c){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();

            int cr = curr.first;
            int cc = curr.second;

            for(int i = 0; i < 4; i++){
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int count = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    count++;
                    bfs(grid, i, j);
                }
            }
        }

        return count;
    }
};