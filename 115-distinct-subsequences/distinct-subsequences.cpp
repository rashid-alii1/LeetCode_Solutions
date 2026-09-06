class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(m + 1, 0)
        );

        // Empty target can always be formed in exactly 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                if (s[i - 1] == t[j - 1]) {

                    long long use = dp[i - 1][j - 1];
                    long long skip = dp[i - 1][j];

                    if (use > INT_MAX - skip) {
                        dp[i][j] = INT_MAX;
                    }
                    else {
                        dp[i][j] = use + skip;
                    }

                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};