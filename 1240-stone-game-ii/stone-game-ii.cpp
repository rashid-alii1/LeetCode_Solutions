class Solution {
public:

    vector<vector<int>> dp;
    vector<int> suffix;
    int n;

    int solve(int i, int M)
    {
        // No piles remaining
        if(i >= n)
            return 0;

        // Already calculated
        if(dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        // We can take 1 to 2*M piles
        for(int X = 1; X <= 2 * M && i + X <= n; X++)
        {
            int newM = max(M, X);

            int opponent =
                solve(i + X, newM);

            int current =
                suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles)
    {
        n = piles.size();

        suffix.resize(n + 1, 0);

        // Build suffix sum
        for(int i = n - 1; i >= 0; i--)
        {
            suffix[i] =
                suffix[i + 1] + piles[i];
        }

        dp.assign(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, 1);
    }
};