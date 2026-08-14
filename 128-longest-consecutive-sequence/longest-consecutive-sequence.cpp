class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> numset(nums.begin(),nums.end());
        int maxlen=0;
        for (auto x : numset)
        {
            if(!numset.count(x-1))
            {
                int currentnum=x;
                int currentlen=1;
                while(numset.count(currentnum+1))
                {
                    currentnum++;
                    currentlen++;
                }
                maxlen=max(maxlen,currentlen);
            }
        }
        return maxlen;
    }
};