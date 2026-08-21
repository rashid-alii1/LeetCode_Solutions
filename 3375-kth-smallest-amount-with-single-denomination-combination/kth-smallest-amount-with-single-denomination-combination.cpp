class Solution {
public:

    long long gcd(long long a, long long b)
    {
        while(b)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    long long lcm(long long a, long long b)
    {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins)
    {
        int n = coins.size();
        long long total = 0;

        for(int mask = 1; mask < (1 << n); mask++)
        {
            long long common = 1;
            int bits = 0;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    common = lcm(common, coins[i]);
                    bits++;

                    if(common > x)
                        break;
                }
            }

            if(common > x)
                continue;

            if(bits % 2 == 1)
                total += x / common;
            else
                total -= x / common;
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k)
    {
        long long left = 1;
        long long right = 1LL * k * (*min_element(coins.begin(),
                                                   coins.end()));

        while(left < right)
        {
            long long mid = left + (right - left) / 2;

            if(count(mid, coins) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};