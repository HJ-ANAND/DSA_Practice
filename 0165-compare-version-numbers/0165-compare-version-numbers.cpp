class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int i = 0, j = 0;

        while(i < n1 || j < n2){
            int u = 0, v = 0;

            while(i < n1 && version1[i] != '.'){
                u = u * 10 + (version1[i]-'0');
                i++;
            }

            while(j < n2 && version2[j] != '.'){
                v = v * 10 + (version2[j]-'0');
                j++;
            }

            if(u < v) return -1;
            if(u > v) return 1;
            i++;
            j++;
        }

        return 0;
    }
};