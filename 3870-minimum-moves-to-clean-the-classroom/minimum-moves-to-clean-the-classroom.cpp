class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;

        // Give every litter cell a bit number
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        // bestEnergy[x][y][mask]
        vector<vector<vector<int>>> bestEnergy(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << litterCount, -1)
            )
        );

        // {x, y, mask, energy, steps}
        queue<array<int, 5>> q;

        q.push({sx, sy, 0, energy, 0});

        bestEnergy[sx][sy][0] = energy;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [x, y, mask, e, steps] = q.front();
            q.pop();

            if (mask == fullMask) {
                return steps;
            }

            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                // Outside grid
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                // Obstacle
                if (classroom[nx][ny] == 'X')
                    continue;

                // Need one energy to make the move
                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter
                if (classroom[nx][ny] == 'L') {
                    int id = litterId[nx][ny];
                    nmask |= (1 << id);
                }

                // Reset energy
                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }

                // Already reached this state with
                // equal or greater energy
                if (ne <= bestEnergy[nx][ny][nmask])
                    continue;

                bestEnergy[nx][ny][nmask] = ne;

                q.push({
                    nx,
                    ny,
                    nmask,
                    ne,
                    steps + 1
                });
            }
        }

        return -1;
    }
};