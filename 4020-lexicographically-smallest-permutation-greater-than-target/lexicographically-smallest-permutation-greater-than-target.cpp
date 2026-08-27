class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
                int freq[26] = {};

        for(char c : s)
            freq[c - 'a']++;

        int n = s.size();

        for(int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Try to use target[i]
            if(freq[x] > 0) {
                freq[x]--;
                continue;
            }

            // Cannot match target[i].
            // Find smallest greater character.
            for(int c = x + 1; c < 26; c++) {

                if(freq[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    freq[c]--;

                    // Add remaining characters
                    for(int j = 0; j < 26; j++) {
                        while(freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            // Need to backtrack.
            break;
        }

        // Restore frequency array
        fill(freq, freq + 26, 0);

        for(char c : s)
            freq[c - 'a']++;

        // Try making the string greater
        // at every possible position from right to left.
        for(int i = n - 1; i >= 0; i--) {

            // Consume target[0 ... i-1]
            bool possible = true;

            int temp[26];

            copy(freq, freq + 26, temp);

            for(int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if(temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if(!possible)
                continue;

            int x = target[i] - 'a';

            // Find smallest character greater than target[i]
            for(int c = x + 1; c < 26; c++) {

                if(temp[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    temp[c]--;

                    // Smallest possible suffix
                    for(int j = 0; j < 26; j++) {
                        while(temp[j] > 0) {
                            ans += char('a' + j);
                            temp[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};