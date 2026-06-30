class Solution {
public:
    void dfs(vector<vector<char>> &grid, int r, int c){
        int row = grid.size();
        int col = grid[0].size();

        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 'X' || grid[r][c] == '$') return;

        grid[r][c] = '$';

        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
    }

    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        for(int i = 0; i < r; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][c-1] == 'O') dfs(board, i, c-1);
        }

        for(int i = 0; i < c; i++){
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[r-1][i] == 'O') dfs(board, r-1, i);
        }

        for(auto &i : board){
            for(auto &j : i){
                if(j == '$') j = 'O';
                else j = 'X';
            }
        }
    }
};