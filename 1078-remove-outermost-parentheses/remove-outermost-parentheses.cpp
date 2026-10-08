class Solution {
public:
    string removeOuterParentheses(string s) {

        string result;
        int depth = 0;

        for (char ch : s) {

            if (ch == '(') {
                
                // If depth > 0, this is NOT an outermost '('
                if (depth > 0) {
                    result += ch;
                }

                depth++;
            }

            else { // ch == ')'

                depth--;

                // If depth > 0, this is NOT an outermost ')'
                if (depth > 0) {
                    result += ch;
                }
            }
        }

        return result;
    }
};