class Solution {
public:
    string smallestNumber(string num, long long t) {

        // Store original value of t
        long long remainingFactor = t;

        // Remove factors from 2 to 9
        for (int factor = 2; factor <= 9; factor++) {
            while (remainingFactor % factor == 0) {
                remainingFactor /= factor;
            }
        }

        // If some prime factor > 9 remains
        if (remainingFactor > 1)
            return "-1";

        int len = num.length();

        vector<long long> requiredFactor(len + 1);
        requiredFactor[0] = t;

        int firstZeroIndex = len - 1;

        // Convert string to character array (string itself is mutable in C++)
        for (int i = 0; i < len; i++) {

            if (num[i] == '0') {
                firstZeroIndex = i;
                break;
            }

            requiredFactor[i + 1] =
                requiredFactor[i] /
                gcd(requiredFactor[i], (long long)(num[i] - '0'));
        }

        // Number already satisfies the condition
        if (requiredFactor[len] == 1)
            return num;

        // Try modifying digits from right to left
        for (int i = firstZeroIndex; i >= 0; i--) {

            while (++num[i] <= '9') {

                long long currentNeed =
                    requiredFactor[i] /
                    gcd(requiredFactor[i], (long long)(num[i] - '0'));

                int candidateDigit = 9;

                // Fill remaining suffix greedily
                for (int j = len - 1; j > i; j--) {

                    while (currentNeed % candidateDigit != 0)
                        candidateDigit--;

                    currentNeed /= candidateDigit;

                    num[j] = char('0' + candidateDigit);
                }

                if (currentNeed == 1)
                    return num;
            }
        }

        // Need a longer number
        string answer = "";

        long long remaining = t;

        for (int digit = 9; digit >= 2; digit--) {

            while (remaining % digit == 0) {
                answer.push_back(char('0' + digit));
                remaining /= digit;
            }
        }

        // Add extra 1's
        int extraOnes = max(len + 1 - (int)answer.length(), 0);

        while (extraOnes--)
            answer.push_back('1');

        reverse(answer.begin(), answer.end());

        return answer;
    }

private:
    long long gcd(long long a, long long b) {

        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }
};