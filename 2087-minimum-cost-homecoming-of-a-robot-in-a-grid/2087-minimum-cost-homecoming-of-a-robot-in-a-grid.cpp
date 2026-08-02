class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];

        int sum = 0;

        if(r1 <= r2){
            for(int i = r1+1; i <= r2; i++){
                sum += rowCosts[i];
            }
        }else{
            for(int i = r2; i < r1; i++){
                sum += rowCosts[i];
            }
        }

        if(c1 <= c2){
            for(int i = c1+1; i <= c2; i++){
                sum += colCosts[i];
            }
        }else{
            for(int i = c2; i < c1; i++){
                sum += colCosts[i];
            }
        }

        return sum; 
    }
};