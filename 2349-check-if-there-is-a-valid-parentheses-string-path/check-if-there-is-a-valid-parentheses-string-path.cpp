class Solution {
public:

    int m, n;

    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {

        // Process the current cell first
        if (grid[i][j] == '(') {
            balance++;
        }
        else {
            balance--;
        }

        // Balance can never become negative
        if (balance < 0) {
            return false;
        }

        // Number of cells still remaining AFTER current cell
        int remaining = (m - 1 - i) + (n - 1 - j);

        // Even if all remaining cells are ')',
        // we cannot reduce balance to 0
        if (balance > remaining) {
            return false;
        }

        // We reached the destination
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        // Already calculated this state
        if (dp[i][j][balance] != -1) {
            return dp[i][j][balance];
        }

        // Move down
        if (i + 1 < m) {
            if (dfs(grid, i + 1, j, balance)) {
                return dp[i][j][balance] = true;
            }
        }

        // Move right
        if (j + 1 < n) {
            if (dfs(grid, i, j + 1, balance)) {
                return dp[i][j][balance] = true;
            }
        }

        return dp[i][j][balance] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // A valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return dfs(grid, 0, 0, 0);
    }
};