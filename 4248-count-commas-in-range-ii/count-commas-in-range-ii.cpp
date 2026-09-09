class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        long long commas = 1;
        while (start <= n) {
            long long end = min(n, start * 1000 - 1); // range of number having same numbers of comma's
            long long count = end - start + 1; // how many numbers in between this range
            ans += count * commas;
            start *= 1000;
            commas++;
        }
        return ans;
    }
};