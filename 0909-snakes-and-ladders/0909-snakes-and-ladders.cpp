class Solution {
public:
    int n;
    pair<int, int> getcor(int num ){
        int rt = (num-1)/n;
        int rb = (n-1) - rt;

        int col = (num-1)%n;
        if((n % 2 == 1 && rb % 2 == 1) || (n % 2 == 0 && rb % 2 == 0)){
            col = (n-1) - col;
        }

        return make_pair(rb, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int step = 0;
        queue<int> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        vis[n-1][0] = true;
        q.push(1);

        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();

                if(curr == n*n) return step;

                for(int i = 1; i <= 6; i++){
                    int val = curr + i;

                    if(val > n*n) break;
                    pair<int, int> cor = getcor(val);
                    int r = cor.first;
                    int c = cor.second;

                    if(vis[r][c]) continue;
                    vis[r][c] = true;
                    if(board[r][c] == -1) q.push(val);
                    else q.push(board[r][c]);
                }
            }
            step++;
        }

        return -1;
    }
};