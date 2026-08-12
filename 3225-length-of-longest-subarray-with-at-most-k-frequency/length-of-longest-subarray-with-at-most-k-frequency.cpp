class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int maxlen=0;
        unordered_map<int,int> freq;
        for(int right=0; right<nums.size();right++)
        {
            freq[nums[right]]++;
            while(freq[nums[right]]>k)
            {
                freq[nums[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);

        }
        return maxlen;
    }
};