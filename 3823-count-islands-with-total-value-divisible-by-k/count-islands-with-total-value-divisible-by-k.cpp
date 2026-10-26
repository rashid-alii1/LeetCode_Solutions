
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        function<long long(int, int)> dfs =
            [&](int r, int c) -> long long {
                visited[r][c] = true;
                long long sum = grid[r][c];

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] > 0 &&
                        !visited[nr][nc]) {
                        sum += dfs(nr, nc);
                    }
                }

                return sum;
            };

        int answer = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    long long islandSum = dfs(r, c);

                    if (islandSum % k == 0) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};
