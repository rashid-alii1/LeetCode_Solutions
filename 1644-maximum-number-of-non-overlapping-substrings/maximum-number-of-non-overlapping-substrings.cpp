class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.length();

        // first[c] = first occurrence of character c
        // last[c]  = last occurrence of character c
        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Step 1: Find first and last occurrence
        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        // Store valid intervals
        vector<pair<int, int>> intervals;

        // Step 2: Build a valid interval for each character
        for (int c = 0; c < 26; c++) {

            // Character does not exist in the string
            if (last[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            // Expand the interval if necessary
            for (int i = left; i <= right; i++) {

                int current = s[i] - 'a';

                // This character appeared before our left boundary.
                // Therefore, we cannot include ALL of its occurrences.
                if (first[current] < left) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of this character.
                right = max(right, last[current]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Step 3: Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {

                 return a.second < b.second;
             });

        // Step 4: Greedily choose non-overlapping intervals
        vector<string> answer;

        int previousEnd = -1;

        for (auto interval : intervals) {

            int left = interval.first;
            int right = interval.second;

            // Non-overlapping
            if (left > previousEnd) {

                answer.push_back(s.substr(left, right - left + 1));

                previousEnd = right;
            }
        }

        return answer;
    }
};