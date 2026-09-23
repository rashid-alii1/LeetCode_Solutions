class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // Step 1: Calculate total sum
        long long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Sum that the remaining subarray must have
        long long target = totalSum - x;

        // If target is negative, impossible
        if (target < 0) {
            return -1;
        }

        // Step 3: Find longest subarray with sum = target
        long long windowSum = 0;

        int left = 0;
        int longestLength = -1;

        for (int right = 0; right < n; right++) {

            // Add current element to window
            windowSum += nums[right];

            // If window sum becomes too large,
            // move left forward
            while (windowSum > target) {
                windowSum -= nums[left];
                left++;
            }

            // We found a subarray with required sum
            if (windowSum == target) {
                int currentLength = right - left + 1;

                longestLength = max(
                    longestLength,
                    currentLength
                );
            }
        }

        // No valid subarray found
        if (longestLength == -1) {
            return -1;
        }

        // Minimum elements removed
        return n - longestLength;
    }
};