class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        int maxsum=sum;
        int left=0;
        int right=k;
        while(right<nums.size())
        {
            sum-=nums[left];
            left++;
            
            sum+=nums[right];
            right++;
            
            maxsum=max(maxsum,sum);
        }
        return (double) maxsum/k;

    }
};