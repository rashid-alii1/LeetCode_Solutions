class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;

        int answer = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry the best previous length forward
            if (right > 0) {
                best[right] = best[right - 1];
            }

            // We found a subarray with sum = target
            if (sum == target) {

                int currentLength = right - left + 1;

                // A previous subarray must end before 'left'
                if (left > 0 && best[left - 1] != INT_MAX) {

                    answer = min(
                        answer,
                        currentLength + best[left - 1]
                    );
                }

                // Current subarray becomes a candidate
                best[right] = min(
                    best[right],
                    currentLength
                );
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};

// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {

//         int n = arr.size();

//         // Store all subarrays whose sum is target.
//         // Each pair = {start, end}
//         vector<pair<int, int>> subarrays;

//         int left = 0;
//         int sum = 0;

//         // Step 1: Find all target-sum subarrays
//         for (int right = 0; right < n; right++) {

//             sum += arr[right];

//             while (sum > target) {
//                 sum -= arr[left];
//                 left++;
//             }

//             if (sum == target) {
//                 subarrays.push_back({left, right});
//             }
//         }

//         // Step 2: Compare every pair
//         int answer = INT_MAX;

//         for (int i = 0; i < subarrays.size(); i++) {

//             int start1 = subarrays[i].first;
//             int end1 = subarrays[i].second;

//             int length1 = end1 - start1 + 1;

//             for (int j = i + 1; j < subarrays.size(); j++) {

//                 int start2 = subarrays[j].first;
//                 int end2 = subarrays[j].second;

//                 int length2 = end2 - start2 + 1;

//                 // They are non-overlapping if
//                 // first ends before second starts.
//                 if (end1 < start2) {
//                     answer = min(answer, length1 + length2);
//                 }
//             }
//         }

//         // No valid pair found
//         return answer == INT_MAX ? -1 : answer;
//     }
// };



