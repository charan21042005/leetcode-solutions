class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        // Check nearby elements to find the repeated one
        for (int i = 0; i < n - 1; i++) {

            // Compare with next element
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }

            // Compare with element two steps ahead
            if (i + 2 < n && nums[i] == nums[i + 2]) {
                return nums[i];
            }

            // Compare with element three steps ahead
            if (i + 3 < n && nums[i] == nums[i + 3]) {
                return nums[i];
            }
        }

        // Fallback (problem guarantees one valid answer)
        return -1;
    }
};
