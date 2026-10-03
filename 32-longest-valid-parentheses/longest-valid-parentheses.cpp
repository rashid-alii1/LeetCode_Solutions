class Solution {
public:
    int longestValidParentheses(string s) {

        int left = 0;
        int right = 0;
        int maxLength = 0;

        // Pass 1: Left -> Right
        for (char ch : s) {

            if (ch == '(') {
                left++;
            }
            else {
                right++;
            }

            // Valid substring found
            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            }

            // Too many ')'
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        // Reset counters
        left = 0;
        right = 0;

        // Pass 2: Right -> Left
        for (int i = s.length() - 1; i >= 0; i--) {

            if (s[i] == '(') {
                left++;
            }
            else {
                right++;
            }

            // Valid substring found
            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            }

            // Too many '('
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return maxLength;
    }
};
