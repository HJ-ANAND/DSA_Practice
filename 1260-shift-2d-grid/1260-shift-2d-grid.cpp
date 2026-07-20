class Solution {
public:
    void solve(vector<vector<int>> &grid){
        int r = grid.size();
        int c = grid[0].size();

        int fill = grid[0][0];

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int temp = grid[i][j];
                grid[i][j] = fill;
                fill = temp;
            }
        }

        grid[0][0] = fill;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i = 0; i < k; i++){
            solve(grid);
        }

        return grid;
    }
};