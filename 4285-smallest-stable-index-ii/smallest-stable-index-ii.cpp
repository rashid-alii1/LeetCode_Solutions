class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             int leftMax = *max_element(
//                 nums.begin(),
//                 nums.begin() + i + 1
//             );

//             int rightMin = *min_element(
//                 nums.begin() + i,
//                 nums.end()
//             );

//             if (leftMax - rightMin <= k)
//                 return i;
//         }

//         return -1;
//     }
// };       
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        int prefixMax = nums[0];
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            //int score = prefixMax - suffixMin[i];
            if ((prefixMax - suffixMin[i]) <= k)
                return i;
        }
        return -1;
    }
};

