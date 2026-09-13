class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int answer = 0;

        // Try every possible row shift
        for (int rowShift = -(n - 1); rowShift <= n - 1; rowShift++) {

            // Try every possible column shift
            for (int colShift = -(n - 1); colShift <= n - 1; colShift++) {

                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {

                    for (int j = 0; j < n; j++) {

                        // We only care about 1s in img1
                        if (img1[i][j] == 0) {
                            continue;
                        }

                        // New position after translation
                        int newRow = i + rowShift;
                        int newCol = j + colShift;

                        // Check if new position is inside the matrix
                        if (newRow >= 0 && newRow < n &&
                            newCol >= 0 && newCol < n) {

                            // Check whether img2 also has 1 there
                            if (img2[newRow][newCol] == 1) {
                                overlap++;
                            }
                        }
                    }
                }

                // Keep the best overlap
                answer = max(answer, overlap);
            }
        }

        return answer;
    }
};