class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char it : s){
            if(it == ')' && !st.empty() && st.top() == '(')st.pop();
            else if(it == ']' && !st.empty() && st.top() == '[')st.pop();
            else if(it == '}' && !st.empty() && st.top() == '{')st.pop();
            else st.push(it);
        }

        return st.empty();
    }
};