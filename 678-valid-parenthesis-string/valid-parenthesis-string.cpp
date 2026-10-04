// class Solution {
// public:
//     bool checkValidString(string s) {

//         int low = 0;
//         int high = 0;

//         for (char ch : s) {

//             if (ch == '(') {
//                 low++;
//                 high++;
//             }

//             else if (ch == ')') {
//                 low--;
//                 high--;
//             }

//             else { // ch == '*'
//                 low--;
//                 high++;
//             }

//             // Balance cannot be negative
//             low = max(low, 0);

//             // Even the maximum possible balance is negative
//             if (high < 0) {
//                 return false;
//             }
//         }

//         // We need at least one possibility with balance 0
//         return low == 0;
//     }
// };



class Solution {
public:
    bool checkValidString(string s) {

        stack<int> openStack;
        stack<int> starStack;

        // First pass
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                openStack.push(i);
            }

            else if (s[i] == '*') {
                starStack.push(i);
            }

            else { // s[i] == ')'

                // Prefer a real '('
                if (!openStack.empty()) {
                    openStack.pop();
                }

                // Otherwise use '*' as '('
                else if (!starStack.empty()) {
                    starStack.pop();
                }

                // No '(' or '*' available
                else {
                    return false;
                }
            }
        }

        // Second pass:
        // Match remaining '(' with '*' acting as ')'
        while (!openStack.empty() && !starStack.empty()) {

            int openIndex = openStack.top();
            int starIndex = starStack.top();

            // '*' must come after '('
            if (openIndex < starIndex) {
                openStack.pop();
                starStack.pop();
            }

            else {
                return false;
            }
        }

        // Every '(' must have been matched
        return openStack.empty();
    }
};