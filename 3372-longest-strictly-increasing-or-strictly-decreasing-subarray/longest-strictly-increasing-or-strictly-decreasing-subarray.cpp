class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int inc=1;
        int dec=1;
        for(int r=1;r<n;r++)
        {
            if(nums[r-1]>nums[r])
            {
                inc=max(inc, r-l+1);
            }
            else
            {
                l=r;
            }
        }
        l=0;
        for(int r=1;r<n;r++)
        {
            if(nums[r-1]<nums[r])
            {
                dec=max(dec, r-l+1);
            }
            else
            {
                l=r;
            }
        }
        return max(inc,dec);
    }
};