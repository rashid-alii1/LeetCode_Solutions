class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixcount;
        prefixcount[0]=1;
        int count=0;
        int prefixsum=0;
        for(auto x: nums)
        {
            prefixsum+=x;
            if(prefixcount.count(prefixsum-k))
            {
                count+=prefixcount[prefixsum-k];
            }
            prefixcount[prefixsum]++;
        }
        return count;
    }
};