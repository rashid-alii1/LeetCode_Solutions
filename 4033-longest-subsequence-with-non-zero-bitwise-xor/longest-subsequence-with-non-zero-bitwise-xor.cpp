class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int xorr = 0;
        bool hasNonZero = false;

        for(int x : nums)
        {
            xorr ^= x;

            if(x != 0)
                hasNonZero = true;
        }

        if(xorr != 0)
            return nums.size();

        if(hasNonZero)
            return nums.size() - 1;

        return 0;
    }
};