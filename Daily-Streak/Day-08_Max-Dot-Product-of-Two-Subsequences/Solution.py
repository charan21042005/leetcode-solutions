class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)

        # dp[i][j] = max dot product using nums1[i:] and nums2[j:]
        dp = [[float('-inf')] * (m + 1) for _ in range(n + 1)]

        # Bottom-up DP
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                take = nums1[i] * nums2[j]
                take += max(0, dp[i + 1][j + 1])

                skip1 = dp[i + 1][j]
                skip2 = dp[i][j + 1]

                dp[i][j] = max(take, skip1, skip2)

        return dp[0][0]

        """
        ===========================
        ❌ WRONG BASE CASE (COMMENTED)
        ===========================
        - Using dp initialized with 0
        - Allows empty subsequence
        - Breaks all-negative cases

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            nums1 = [2, 1, -2, 5]
            nums2 = [3, 0, -6]

            sol = Solution()
            print(sol.maxDotProduct(nums1, nums2))

        if __name__ == "__main__":
            main()
        """
