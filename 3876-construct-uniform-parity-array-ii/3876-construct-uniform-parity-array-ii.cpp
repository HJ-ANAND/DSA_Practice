class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n == 1) return true;

        int sodd = INT_MAX;
        int seven = INT_MAX;

        for(int i : nums1){
            if(i%2 == 0) seven = min(seven, i);
            else sodd = min(sodd, i);
        }

        if(sodd == INT_MAX || seven == INT_MAX) return true;

        return sodd < seven ? true : false;
    }
};