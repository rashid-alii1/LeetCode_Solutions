class Solution {
public:
string buildPalindrome(const string& half, char middle)
    {
        string ans = half;

        // For odd length
        if (middle != '\0')
            ans += middle;

        // Mirror the first half
        for (int i = (int)half.size() - 1; i >= 0; i--)
            ans += half[i];

        return ans;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int halfLen = n / 2;

        // ------------------------------------
        // 1. Count characters
        // ------------------------------------

        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        // ------------------------------------
        // 2. Check whether palindrome exists
        // ------------------------------------

        int oddCount = 0;
        char middle = '\0';

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 != 0)
            {
                oddCount++;
                middle = char('a' + i);
            }
        }

        if (n % 2 == 0)
        {
            if (oddCount != 0)
                return "";
        }
        else
        {
            if (oddCount != 1)
                return "";
        }

        // ------------------------------------
        // 3. Frequency available for first half
        // ------------------------------------

        int halfFreq[26];

        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        // ------------------------------------
        // 4. First check whether the exact
        //    target first half can be formed
        // ------------------------------------

        string targetHalf = target.substr(0, halfLen);

        int temp[26];

        for (int i = 0; i < 26; i++)
            temp[i] = halfFreq[i];

        bool canMakeTargetHalf = true;

        for (char c : targetHalf)
        {
            int x = c - 'a';

            if (temp[x] == 0)
            {
                canMakeTargetHalf = false;
                break;
            }

            temp[x]--;
        }

        // If we can make exactly targetHalf,
        // construct the palindrome and check it.
        if (canMakeTargetHalf)
        {
            string candidate =
                buildPalindrome(targetHalf, middle);

            if (candidate > target)
                return candidate;
        }

        // ------------------------------------
        // 5. Find the smallest first half
        //    STRICTLY greater than targetHalf
        // ------------------------------------

        for (int pivot = halfLen - 1; pivot >= 0; pivot--)
        {
            // Fresh copy of frequencies
            for (int i = 0; i < 26; i++)
                temp[i] = halfFreq[i];

            // Try to match targetHalf before pivot
            bool possible = true;

            for (int i = 0; i < pivot; i++)
            {
                int x = targetHalf[i] - 'a';

                if (temp[x] == 0)
                {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            // --------------------------------
            // At pivot:
            // choose smallest character >
            // targetHalf[pivot]
            // --------------------------------

            int x = targetHalf[pivot] - 'a';

            for (int c = x + 1; c < 26; c++)
            {
                if (temp[c] == 0)
                    continue;

                // Prefix remains equal
                string half = targetHalf.substr(0, pivot);

                // Make this position slightly bigger
                half += char('a' + c);

                temp[c]--;

                // --------------------------------
                // Fill remaining positions with
                // smallest possible characters
                // --------------------------------

                for (int j = 0; j < 26; j++)
                {
                    while (temp[j] > 0)
                    {
                        half += char('a' + j);
                        temp[j]--;
                    }
                }

                string candidate =
                    buildPalindrome(half, middle);

                return candidate;
            }
        }

        return "";
    }
};
