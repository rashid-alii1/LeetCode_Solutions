class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        // Option 1: Change the two smallest elements
        ans = min(ans, nums[n - 1] - nums[2]);

        // Option 2: Change the smallest and largest elements
        ans = min(ans, nums[n - 2] - nums[1]);

        // Option 3: Change the two largest elements
        ans = min(ans, nums[n - 3] - nums[0]);

        return ans;
    }
};