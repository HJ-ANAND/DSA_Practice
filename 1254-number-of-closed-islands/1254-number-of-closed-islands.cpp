class Solution {
public:
    bool dfs(vector<vector<int>> &grid, int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || r >= row || c < 0 || c >= col) return false;

        if(grid[r][c] == 1) return true;

        grid[r][c] = 1;

        bool right = dfs(grid, r, c+1);
        bool left = dfs(grid, r, c-1);
        bool down = dfs(grid, r+1, c);
        bool up = dfs(grid, r-1, c);

        return right && left && down && up;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;

        for(int i = 1; i < row-1; i++){
            for(int j = 1; j < col-1; j++){
                if(grid[i][j] == 0 && dfs(grid, i, j)){
                    ans++;
                }
            }
        }

        return ans;

    }
};