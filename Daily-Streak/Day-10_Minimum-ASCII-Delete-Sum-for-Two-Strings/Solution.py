class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n, m = len(s1), len(s2)

        # dp[i][j] = minimum ASCII delete sum
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # Base case: s2 exhausted
        for i in range(n - 1, -1, -1):
            dp[i][m] = dp[i + 1][m] + ord(s1[i])

        # Base case: s1 exhausted
        for j in range(m - 1, -1, -1):
            dp[n][j] = dp[n][j + 1] + ord(s2[j])

        # Bottom-up DP
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if s1[i] == s2[j]:
                    dp[i][j] = dp[i + 1][j + 1]
                else:
                    dp[i][j] = min(
                        ord(s1[i]) + dp[i + 1][j],
                        ord(s2[j]) + dp[i][j + 1]
                    )

        return dp[0][0]

        """
        ===========================
        ❌ NAIVE IDEA (COMMENTED)
        ===========================
        - Try all delete combinations
        - Exponential complexity
        - Not feasible

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            s1 = "sea"
            s2 = "eat"

            sol = Solution()
            print(sol.minimumDeleteSum(s1, s2))

        if __name__ == "__main__":
            main()
        """
