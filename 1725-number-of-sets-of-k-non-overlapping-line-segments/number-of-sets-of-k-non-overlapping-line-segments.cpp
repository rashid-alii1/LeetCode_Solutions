class Solution {
public:
    int numberOfSets(int n, int k) {

        const long long MOD = 1000000007;

        long long ans = 1;

        int r = 2 * k;
        int N = n + k - 1;

        // C(N, r)
        for (int i = 1; i <= r; i++) {

            ans = ans * (N - r + i) % MOD;

            // Modular inverse of i
            long long power = MOD - 2;
            long long base = i;
            long long inverse = 1;

            while (power > 0) {
                if (power & 1) {
                    inverse = inverse * base % MOD;
                }

                base = base * base % MOD;
                power /= 2;
            }

            ans = ans * inverse % MOD;
        }

        return ans;
    }
};