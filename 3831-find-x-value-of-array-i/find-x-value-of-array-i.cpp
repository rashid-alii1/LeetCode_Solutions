class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> answer(k, 0);

        // Number of subarrays ending at the previous index
        // for each possible remainder.
        vector<long long> current(k, 0);

        for (int num : nums) {

            vector<long long> next(k, 0);

            int value = num % k;

            // Start a new subarray with just num.
            next[value]++;

            // Extend every previous subarray by num.
            for (int r = 0; r < k; r++) {

                int newRemainder = (r * value) % k;

                next[newRemainder] += current[r];
            }

            // Add all subarrays ending at this position
            // to the final answer.
            for (int r = 0; r < k; r++) {
                answer[r] += next[r];
            }

            current = next;
        }

        return answer;
    }
};

// class Solution {
// public:
//     vector<long long> resultArray(vector<int>& nums, int k) {

//         int n = nums.size();
//         vector<long long> result(k, 0);

//         for (int i = 0; i < n; i++) {

//             int product = 1;

//             for (int j = i; j < n; j++) {

//                 product = (product * (nums[j] % k)) % k;

//                 result[product]++;
//             }
//         }

//         return result;
//     }
// };        