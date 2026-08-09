class Solution {
public:
    int n;
    int t[2][101][101];
    int solve (vector<int> &piles, int person, int st, int M){
        if(st >= n) return 0;

        if(t[person][st][M] != -1) return t[person][st][M];

        int stone = 0;
        int result = (person == 1) ? -1 : INT_MAX;

        for(int i = 1; i <= min(2*M, n-st); i++){
            stone += piles[st + i - 1];
            if(person == 1){
                result = max(result, stone+solve(piles, 0, st + i, max(M, i)));
            }else{
                result = min(result, solve(piles, 1, st + i, max(M, i)));
            }
        }

        return t[person][st][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        return solve(piles, 1, 0, 1);
    }
};