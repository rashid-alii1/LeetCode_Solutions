class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves=0;
        int large=*max_element(nums.begin(), nums.end());
        for(auto num: nums)
        {
            moves+=abs(large-num);
        }
        return moves;
    }
};