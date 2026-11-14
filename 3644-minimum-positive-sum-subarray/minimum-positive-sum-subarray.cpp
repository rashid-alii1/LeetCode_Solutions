class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();

        // Step 1: Build prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Find minimum positive subarray sum
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {

            for (int j = i + l - 1; j < n && j - i + 1 <= r; j++) {

                int sum = prefix[j + 1] - prefix[i];

                if (sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};