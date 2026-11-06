class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Step 1: Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Step 2: Store each query with its original index
        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        // Step 3: Initialize answer and frequency array
        vector<int> ans(queries.size());
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        // Step 4: Process queries in sorted order
        for (auto& q : sortedQueries) {

            int time = q.first;
            int index = q.second;

            int windowStart = time - x;

            // Add logs with timestamp <= query time
            while (right < logs.size() &&
                   logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs with timestamp < window start
            while (left < right &&
                   logs[left][1] < windowStart) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    active--;
                }

                left++;
            }

            // Total servers minus active servers
            ans[index] = n - active;
        }

        return ans;
    }
};