class Solution {
public:
    int count(vector<vector<int>>& img1, vector<vector<int>>& img2, int roff, int coff, int &n){
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int b_i = i+roff;
                int b_j = j+coff;

                if(b_i < 0 || b_i >= n || b_j < 0 || b_j >= n) continue;
                if(img1[i][j] && img2[b_i][b_j]) count++;
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = INT_MIN;

        for(int i = -n+1; i < n; i++){
            for(int j = -n+1; j < n; j++){
                ans = max(ans, count(img1, img2, i, j, n));
            }
        }

        return ans;
    }
};