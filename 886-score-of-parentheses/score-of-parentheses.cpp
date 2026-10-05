class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;

        // Score outside all parentheses
        st.push(0);

        for (char ch : s) {

            // Enter a new nesting level
            if (ch == '(') {
                st.push(0);
            }

            // Leave the current nesting level
            else {

                // Get score inside current pair
                int innerScore = st.top();
                st.pop();

                int score;

                // "()" = 1
                if (innerScore == 0) {
                    score = 1;
                }

                // "(A)" = 2 * A
                else {
                    score = 2 * innerScore;
                }

                // Add current score to parent level
                st.top() += score;
            }
        }

        // Total score
        return st.top();
    }
};