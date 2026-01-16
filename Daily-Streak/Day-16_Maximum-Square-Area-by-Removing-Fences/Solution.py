class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: list[int], vFences: list[int]) -> int:
        # ✅ OPTIMAL APPROACH:
        # Square side must exist in BOTH
        # horizontal and vertical directions.

        MOD = 10**9 + 7

        # Add boundary fences
        h = hFences + [1, m]
        v = vFences + [1, n]

        h.sort()
        v.sort()

        # Store all horizontal distances
        horizontal_distances = set()
        for i in range(len(h)):
            for j in range(i + 1, len(h)):
                horizontal_distances.add(h[j] - h[i])

        max_side = -1

        # Match vertical distances
        for i in range(len(v)):
            for j in range(i + 1, len(v)):
                dist = v[j] - v[i]
                if dist in horizontal_distances:
                    max_side = max(max_side, dist)

        if max_side == -1:
            return -1

        return (max_side * max_side) % MOD

        """
        ===========================
        ❌ WRONG IDEA (COMMENTED)
        ===========================
        - Longest consecutive gap only
        - Misses square constraint

        ===========================
        🧪 STANDALONE TEST (COMMENTED)
        ===========================
        if __name__ == "__main__":
            s = Solution()
            print(s.maximizeSquareArea(4, 3, [2,3], [2]))  # 4
        """
