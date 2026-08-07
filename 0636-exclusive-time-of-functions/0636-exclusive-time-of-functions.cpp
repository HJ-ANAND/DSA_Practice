class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);

        int prevTime = 0;

        for (string &s : logs) {
            int first = s.find(':');
            int last = s.rfind(':');

            int id = stoi(s.substr(0, first));
            string type = s.substr(first + 1, last - first - 1);
            int time = stoi(s.substr(last + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }

                st.push(id);
                prevTime = time;
            }
            else { // end
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return ans;
    }
};