class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        // Store knowledge in hash map
        for (auto& item : knowledge) {
            mp[item[0]] = item[1];
        }

        string answer;

        int i = 0;

        while (i < s.length()) {

            // Normal character
            if (s[i] != '(') {

                answer += s[i];
                i++;
            }

            // Bracket pair
            else {

                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Look up key
                if (mp.count(key)) {
                    answer += mp[key];
                }
                else {
                    answer += "?";
                }

                // Move after ')'
                i = j + 1;
            }
        }

        return answer;
    }
};