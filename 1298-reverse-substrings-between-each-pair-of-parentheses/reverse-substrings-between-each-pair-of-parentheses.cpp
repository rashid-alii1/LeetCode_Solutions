class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string current = "";

        for (char ch : s) {

            // Opening bracket
            if (ch == '(') {

                st.push(current);
                current = "";
            }

            // Closing bracket
            else if (ch == ')') {

                reverse(current.begin(), current.end());

                current = st.top() + current;
                st.pop();
            }

            // Normal character
            else {

                current += ch;
            }
        }

        return current;
    }
};