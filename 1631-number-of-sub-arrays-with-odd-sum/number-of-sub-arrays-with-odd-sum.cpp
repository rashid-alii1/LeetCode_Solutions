class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        const int MOD = 1e9 + 7;

        int odd = 0;
        int even = 1;

        int prefix = 0;
        long long ans = 0;

        for (int num : arr) {

            prefix += num;

            if (prefix % 2 == 0) {
                ans += odd;
                even++;
            }
            else {
                ans += even;
                odd++;
            }

            ans %= MOD;
        }

        return ans;
    }
};