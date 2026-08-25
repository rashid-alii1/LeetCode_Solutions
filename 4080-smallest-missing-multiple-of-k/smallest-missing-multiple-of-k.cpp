class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(),nums.end());
        for(int multiple = k; ; multiple += k)
        {
            if(present.find(multiple) == present.end())
            {
                return multiple;
            }
        }
    }
};