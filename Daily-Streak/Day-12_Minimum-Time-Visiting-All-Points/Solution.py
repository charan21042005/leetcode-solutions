class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        # ✅ OPTIMAL GREEDY APPROACH (ACTIVE)
        time = 0

        for i in range(1, len(points)):
            dx = abs(points[i][0] - points[i - 1][0])
            dy = abs(points[i][1] - points[i - 1][1])

            # Diagonal movement minimizes time
            time += max(dx, dy)

        return time

        """
        ===========================
        🧠 INTUITION (COMMENTED)
        ===========================
        - Diagonal move = (x+1, y+1)
        - Use diagonals until one axis aligns
        - Remaining moves are straight

        ===========================
        ❌ SIMULATION IDEA (COMMENTED)
        ===========================
        - While current != target:
            move step by step
        - Correct but verbose

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            points = [[1,1],[3,4],[-1,0]]
            sol = Solution()
            print(sol.minTimeToVisitAllPoints(points))

        if __name__ == "__main__":
            main()
        """
