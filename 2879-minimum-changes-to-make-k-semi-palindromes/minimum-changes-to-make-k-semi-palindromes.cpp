
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // Step 1: Precompute substring costs
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len++) {

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Check each group
                    for (int r = 0; r < d; r++) {

                        int left = r;
                        int right = r + ((len - 1 - r) / d) * d;

                        // Check palindrome
                        while (left < right) {

                            if (s[i + left] != s[i + right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][i + len - 1] =
                        min(cost[i][i + len - 1], changes);
                }
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(k + 1,
                               vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {

            for (int i = 2 * p; i <= n; i++) {

                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    if (dp[p - 1][j] == INF)
                        continue;

                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
