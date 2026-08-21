class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, vector<int>> rows;

        for (auto &seat : reservedSeats) {
            rows[seat[0]].push_back(seat[1]);
        }

        int count = 2 * n;

        for (auto &[row, seats] : rows) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat : seats) {

                if (seat >= 2 && seat <= 5) left = false;

                if (seat >= 4 && seat <= 7) middle = false;

                if (seat >= 6 && seat <= 9) right = false;
            }


            if (left && right) {
                // Still 2 families → nothing to change
            }
            else if (left || middle || right) count--;
            else count -= 2;
            
        }

        return count;
    }
};