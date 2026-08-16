class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& at) {
        int mxlight = *max_element(lights.begin(), lights.end());
        int ans = 0;

        for(auto &t : at){
            int r = t % period;

            int wait = (r < mxlight) ? 0 : period - r;

            ans = max(ans, wait);
        }

        return ans;
    }
};