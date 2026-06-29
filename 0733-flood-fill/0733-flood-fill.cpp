class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, int color, int ori){
        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != ori) return;

        grid[r][c] = color;

        dfs(grid, r, c+1, color, ori);
        dfs(grid, r, c-1, color, ori);
        dfs(grid, r+1, c, color, ori);
        dfs(grid, r-1, c, color, ori);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];

        if(original == color) return image;

        dfs(image, sr, sc, color, original);

        return image;
    }
};