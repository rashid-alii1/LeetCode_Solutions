class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present;
        for(int x : nums)
        {
            present.insert(x);
        }
        for(int multiple = k; ; multiple += k)
        {
            if(present.count(multiple) == 0)
            {
                return multiple;
            }
        }
    }
};