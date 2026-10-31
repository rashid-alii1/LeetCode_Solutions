#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // Ways entering each cell from above
        vector<long long> down(n, 0);

        // Process the grid row by row
        for (int i = 0; i < m; i++) {

            // Ways entering current cell from the left
            long long left = (i == 0 ? 1 : 0);

            for (int j = 0; j < n; j++) {

                long long up = down[j];

                // Destination reached
                if (i == m - 1 && j == n - 1) {
                    return (left + up) % MOD;
                }

                long long newRight;
                long long newDown;

                if (grid[i][j] == 0) {

                    // Empty cell: can move right or down
                    long long total = (left + up) % MOD;

                    newRight = total;
                    newDown = total;

                } else {

                    // Mirror: swap the incoming directions
                    newRight = up;
                    newDown = left;
                }

                // Move right: next cell in the same row
                left = newRight;

                // Move down: next row, same column
                down[j] = newDown;
            }
        }

        return 0;
    }
};