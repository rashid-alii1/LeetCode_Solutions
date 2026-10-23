
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> misplaced;

        // Step 1: Collect misplaced elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                misplaced.push_back(nums[i]);
            }
        }

        // Step 2: If everything is already sorted
        if (misplaced.empty()) {
            return 0;
        }

        // Step 3: AND all misplaced elements
        int k = misplaced[0];

        for (int i = 1; i < misplaced.size(); i++) {
            k &= misplaced[i];
        }

        return k;
    }
};
