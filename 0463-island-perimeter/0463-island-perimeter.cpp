class Solution {
public:
    int dfs(vector<vector<int>> &grid, int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0) return 1;

        if(grid[r][c] == -1) return 0;

        grid[r][c] = -1;

        return dfs(grid, r, c+1)
        + dfs(grid, r, c-1)
        + dfs(grid, r+1, c)
        + dfs(grid, r-1, c);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]) return dfs(grid, i, j);
            }
        }           

        return 0;
    }
};