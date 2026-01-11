class Solution:
    # Helper: Largest Rectangle in Histogram
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        max_area = 0
        n = len(heights)

        for i in range(n + 1):
            curr_height = 0 if i == n else heights[i]

            while stack and curr_height < heights[stack[-1]]:
                h = heights[stack.pop()]
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, h * width)

            stack.append(i)

        return max_area

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # ✅ OPTIMAL APPROACH: Histogram + Monotonic Stack
        if not matrix:
            return 0

        cols = len(matrix[0])
        heights = [0] * cols
        max_rectangle = 0

        for row in matrix:
            for j in range(cols):
                if row[j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0

            max_rectangle = max(
                max_rectangle,
                self.largestRectangleArea(heights)
            )

        return max_rectangle

        """
        ===========================
        ❌ BRUTE FORCE IDEA (COMMENTED)
        ===========================
        - Try all rectangles
        - Validate each cell
        - Not feasible

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            matrix = [
                ['1','0','1','0','0'],
                ['1','0','1','1','1'],
                ['1','1','1','1','1'],
                ['1','0','0','1','0']
            ]
            sol = Solution()
            print(sol.maximalRectangle(matrix))

        if __name__ == "__main__":
            main()
        """
