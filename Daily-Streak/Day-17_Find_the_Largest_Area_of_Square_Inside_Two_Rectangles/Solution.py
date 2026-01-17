class Solution:
    def largestSquareArea(self, bottomLeft, topRight) -> int:
        # ✅ OPTIMAL APPROACH: Brute Force + Math

        n = len(bottomLeft)
        ans = 0

        # Try all rectangle pairs
        for i in range(n):
            for j in range(i + 1, n):

                left   = max(bottomLeft[i][0], bottomLeft[j][0])
                right  = min(topRight[i][0],  topRight[j][0])
                bottom = max(bottomLeft[i][1], bottomLeft[j][1])
                top    = min(topRight[i][1],  topRight[j][1])

                width  = right - left
                height = top - bottom

                if width <= 0 or height <= 0:
                    continue

                side = min(width, height)
                ans = max(ans, side * side)

        return ans


"""
==========================
🧪 STANDALONE TEST
==========================
if __name__ == "__main__":
    bottomLeft = [[1,1],[2,2],[1,2]]
    topRight   = [[3,3],[4,4],[3,4]]

    s = Solution()
    print(s.largestSquareArea(bottomLeft, topRight))
"""
