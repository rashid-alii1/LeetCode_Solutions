class Solution {
public:

    unordered_set<string> result;

    void dfs(string& s,
             int index,
             int leftRem,
             int rightRem,
             int open,
             string& current) {

        // We processed the entire string
        if (index == s.length()) {

            if (leftRem == 0 &&
                rightRem == 0 &&
                open == 0) {

                result.insert(current);
            }

            return;
        }

        char ch = s[index];

        // =========================================
        // CASE 1: '('
        // =========================================

        if (ch == '(') {

            // Option 1: Remove this '('
            if (leftRem > 0) {

                dfs(
                    s,
                    index + 1,
                    leftRem - 1,
                    rightRem,
                    open,
                    current
                );
            }

            // Option 2: Keep this '('
            current.push_back('(');

            dfs(
                s,
                index + 1,
                leftRem,
                rightRem,
                open + 1,
                current
            );

            current.pop_back();
        }

        // =========================================
        // CASE 2: ')'
        // =========================================

        else if (ch == ')') {

            // Option 1: Remove this ')'
            if (rightRem > 0) {

                dfs(
                    s,
                    index + 1,
                    leftRem,
                    rightRem - 1,
                    open,
                    current
                );
            }

            // Option 2: Keep this ')'
            if (open > 0) {

                current.push_back(')');

                dfs(
                    s,
                    index + 1,
                    leftRem,
                    rightRem,
                    open - 1,
                    current
                );

                current.pop_back();
            }
        }

        // =========================================
        // CASE 3: Letter
        // =========================================

        else {

            current.push_back(ch);

            dfs(
                s,
                index + 1,
                leftRem,
                rightRem,
                open,
                current
            );

            current.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // -----------------------------------------
        // Find how many '(' and ')' must be removed
        // -----------------------------------------

        for (char ch : s) {

            if (ch == '(') {
                leftRem++;
            }

            else if (ch == ')') {

                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        string current = "";

        dfs(
            s,
            0,
            leftRem,
            rightRem,
            0,
            current
        );

        return vector<string>(
            result.begin(),
            result.end()
        );
    }
};