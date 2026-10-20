// class Solution {
// public:
//     int sortableIntegers(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sorted = nums;
//         sort(sorted.begin(), sorted.end());
//         int answer = 0;
//         for (int k = 1; k <= n; k++) {
//             if (n % k != 0)
//                 continue;
//             bool sortable = true;
//             for (int start = 0; start < n; start += k) {
//                 vector<int> doubled;
//                 for (int j = 0; j < 2 * k; j++)
//                     doubled.push_back(nums[start + j % k]);
//                 if (search(doubled.begin(), doubled.end(),
//                            sorted.begin() + start,
//                            sorted.begin() + start + k)
//                     == doubled.end()) {
//                     sortable = false;
//                     break;
//                 }
//             }
//             if (sortable)
//                 answer += k;
//         }
//         return answer;
//     }
// };

class Solution {
private:
    // Check whether nums[start ... start+k-1]
    // can be rotated to match sorted[start ... start+k-1].
    bool isRotation(vector<int>& nums, vector<int>& sorted,
                    int start, int k) {
        vector<int> pattern(k);

        for (int i = 0; i < k; i++) {
            pattern[i] = sorted[start + i];
        }

        // Build KMP prefix table.
        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k; ) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search in two virtual copies of the original block.
        // Length 2*k-1 is enough to contain every rotation.
        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int value = nums[start + (i % k)];

            while (j > 0 && value != pattern[j]) {
                j = lps[j - 1];
            }

            if (value == pattern[j]) {
                j++;
            }

            if (j == k) {
                return true;
            }
        }

        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int answer = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool sortable = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sorted, start, k)) {
                    sortable = false;
                    break;
                }
            }

            if (sortable) {
                answer += k;
            }
        }

        return answer;
    }
};