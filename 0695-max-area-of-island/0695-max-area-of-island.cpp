class Solution {
public:
    int area(vector<vector<int>> &grid, int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        return 1 + area(grid, r, c+1) 
        + area(grid, r, c-1) 
        + area(grid, r+1, c) 
        + area(grid, r-1, c);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int ans = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    int ar = area(grid, i, j);
                    ans = max(ar, ans);
                }
            }
        }

        return ans;
    }
};