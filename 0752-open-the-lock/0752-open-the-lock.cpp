class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if(dead.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        vis.insert("0000");

        int move = 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                string curr = q.front();
                q.pop();

                if(curr == target) return move;

                for(int i = 0; i < 4; i++){
                    string next = curr;
                    next[i] = (curr[i] == '9') ? '0' : ((curr[i] - '0') + 1) + '0';
                    if(!dead.count(next) && !vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                    next = curr;
                    next[i] = (curr[i] == '0') ? '9' : ((curr[i] - '0') - 1) + '0';
                    if(!dead.count(next) && !vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            move++;
        }

        return -1;
    }
};