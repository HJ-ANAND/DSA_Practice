class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int para = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j]){
                    para += 4;

                    if(j + 1 < c && grid[i][j] && grid[i][j+1]){
                        para -= 2;
                    }
                    if(i + 1 < r && grid[i][j] && grid[i+1][j]){
                        para -= 2;
                    }
                }
            }
        }

        return para;
    }
};