class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        if(n == 1 || m == 1) return 0;
        if(n == m) return 1;

        vector<int> left(n);
        vector<int> right(n);
        int j = 0;

        for(int i = 0; i < n; i++){
            while(skill[i] != station[j]) j++;

            left[i] = j;
            j++;
        }

        j = m-1;

        for(int i = n-1; i >= 0; i--){
            while(skill[i] != station[j]) j--;

            right[i] = j;
            j--;
        }

        int ans = INT_MIN;

        for(int i = 0; i < n-1; i++){
            ans = max(ans, right[i+1] - left[i]);
        }

        return ans;
    }
};