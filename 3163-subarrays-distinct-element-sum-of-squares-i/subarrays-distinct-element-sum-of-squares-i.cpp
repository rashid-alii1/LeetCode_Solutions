class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int start = 0; start < n; start++) {
            set<int> s;

            for (int end = start; end < n; end++) {
                s.insert(nums[end]);

                int distinctCount = s.size();
                sum += distinctCount * distinctCount;
            }
        }

        return sum;
    }
};