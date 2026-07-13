class Solution {
public:
    vector<char> dict = {'A', 'C', 'G', 'T'};
    int minMutation(string sw, string ew, vector<string>& bank) {
        unordered_set<string> lis(bank.begin(), bank.end());
        unordered_set<string> vis;
        queue<string> q;

        if(!lis.count(ew) || sw == ew) return -1;

        q.push(sw);
        vis.insert(sw);
        int step = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == ew) return step;

                for(int i = 0; i < curr.size(); i++){
                    string next = curr;
                    for(char ch : dict){
                        next[i] = ch;
                        if(!vis.count(next) && lis.count(next)){
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            step++;
        }

        return -1;
    }
};