class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0 || grid[r][c] == -1) return;

        grid[r][c] = -1;

        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        for(int i = 0; i < r; i++){
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][c-1] == 1) dfs(grid, i, c-1);
        }

        for(int i = 0; i < c; i++){
            if(grid[0][i] == 1) dfs(grid, 0, i);
            if(grid[r-1][i] == 1) dfs(grid, r-1, i);
        }

        int count = 0;

        for(auto i : grid){
            for(auto j : i){
                if(j == 1) count++;
            }
        }

        return count;
    }
};