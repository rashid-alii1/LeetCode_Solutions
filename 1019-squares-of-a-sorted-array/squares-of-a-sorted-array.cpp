class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i=0; i<=nums.size()-1;i++){
            nums[i]=nums[i]*nums[i];

        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};