class Solution {
public:
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {1, -1, 0, 0};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false)); 

        for(auto &i : isWater){
            for(auto &j : i){
                if(j == 1) j = 0;
                else j = 1;
            }
        }

        queue<pair<int, int>> q;
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isWater[i][j] == 0){
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
                    isWater[nr][nc] = isWater[r][c] + 1;
                }
            }
        }

        return isWater;
    }
};