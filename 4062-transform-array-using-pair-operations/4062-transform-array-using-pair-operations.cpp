class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(source.size() != target.size())
            return false;

        long long s1 = 0, s2 = 0;

        for(int i = 0; i < source.size(); i++) {
            s1 += source[i];
            s2 += target[i];
        }

        return s1 == s2;
    }
};