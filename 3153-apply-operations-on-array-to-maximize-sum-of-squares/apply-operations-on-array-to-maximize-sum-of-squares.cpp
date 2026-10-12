
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        vector<int> bits(31, 0);

        // Step 1: Count set bits at each position
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if (num & (1 << b)) {
                    bits[b]++;
                }
            }
        }

        long long answer = 0;

        // Step 2: Construct k maximum values
        for (int i = 0; i < k; i++) {
            long long value = 0;

            for (int b = 0; b < 31; b++) {
                if (bits[b] > 0) {
                    value |= (1LL << b);
                    bits[b]--;
                }
            }

            // Step 3: Add the square modulo MOD
            answer = (answer + value * value) % MOD;
        }

        return answer;
    }
};