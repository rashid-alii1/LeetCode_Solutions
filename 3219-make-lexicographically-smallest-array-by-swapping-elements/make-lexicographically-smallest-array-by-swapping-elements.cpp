class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        vector<int> result(n);

        int start = 0;

        while (start < n) {

            int end = start;

            // Find the connected component
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Collect original indices
            vector<int> positions;

            for (int i = start; i <= end; i++) {
                positions.push_back(arr[i].second);
            }

            // Smallest original positions first
            sort(positions.begin(), positions.end());

            // Values are already sorted
            for (int i = 0; i < positions.size(); i++) {
                result[positions[i]] = arr[start + i].first;
            }

            start = end + 1;
        }

        return result;
    }
};