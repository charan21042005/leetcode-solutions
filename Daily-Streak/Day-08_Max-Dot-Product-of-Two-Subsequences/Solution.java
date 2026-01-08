class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        int[][] dp = new int[n + 1][m + 1];

        // Initialize with very small values (to avoid empty subsequence)
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE);
        }

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j];
                if (dp[i + 1][j + 1] != Integer.MIN_VALUE) {
                    take += Math.max(0, dp[i + 1][j + 1]);
                }

                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = Math.max(take, Math.max(skip1, skip2));
            }
        }

        return dp[0][0];
    }

    /*
    ===========================
    ❌ INCORRECT APPROACH (COMMENTED)
    ===========================
    - Greedy pairing largest values
    - Fails with negative numbers

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    public static void main(String[] args) {
        int[] nums1 = {2, 1, -2, 5};
        int[] nums2 = {3, 0, -6};

        Solution s = new Solution();
        System.out.println(s.maxDotProduct(nums1, nums2));
    }
    */
}
