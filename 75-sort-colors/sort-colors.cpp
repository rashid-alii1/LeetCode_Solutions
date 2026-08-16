class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low  = 0;                  // boundary for 0s
        int mid  = 0;                  // current element
        int high = nums.size() - 1;    // boundary for 2s

        while (mid <= high) {
            if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++; 
            }
            else {   
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
