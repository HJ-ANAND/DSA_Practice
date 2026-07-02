class Solution {
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false)); 
        queue<pair<int, int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                    mat[nr][nc] = mat[r][c] + 1;
                }
            }
        }

        return mat;
    }
};