class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) return 1;

        bool minInPrefix = false;
        bool maxInSuffix = false;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == mn) minInPrefix = true;
        }

        for (int i = 1; i < n; i++) {
            if (s[i] == mx) maxInSuffix = true;
        }

        if (minInPrefix || maxInSuffix) return 2;

        return 3;
    }
};