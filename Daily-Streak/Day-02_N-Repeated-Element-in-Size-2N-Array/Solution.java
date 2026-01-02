class Solution {
    public int repeatedNTimes(int[] nums) {
        int n = nums.length;

        // Traverse the array and check nearby elements
        for (int i = 0; i < n - 1; i++) {

            // Check adjacent element
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }

            // Check element two steps ahead
            if (i + 2 < n && nums[i] == nums[i + 2]) {
                return nums[i];
            }

            // Check element three steps ahead
            if (i + 3 < n && nums[i] == nums[i + 3]) {
                return nums[i];
            }
        }

        // Guaranteed answer exists as per problem
        return -1;
    }
}
