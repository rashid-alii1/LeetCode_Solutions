class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.size()<3) return {};
        set<vector<int>> unique_triplet;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0)
                {
                    unique_triplet.insert
                    (
                        {
                            nums[i],
                            nums[left],
                            nums[right]
                        }
                    );
                    left++;
                    right--;
                }
                else if(sum>0) 
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        vector<vector<int>> result
        (
            unique_triplet.begin(),unique_triplet.end()
        );
        return result;    
    }
};