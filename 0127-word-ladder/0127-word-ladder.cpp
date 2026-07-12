class Solution {
public:
    int ladderLength(string sw, string ew, vector<string>& wordList) {
        unordered_set<string> lis(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        queue<string> q;

        if(!lis.count(ew)) return 0;

        q.push(sw);
        vis.insert(sw);
        int step = 1;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == ew) return step;

                for(int i = 0; i < curr.size(); i++){
                    string next = curr;
                    for(char ch = 'a'; ch <= 'z'; ch++){
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

        return 0;
    }
};