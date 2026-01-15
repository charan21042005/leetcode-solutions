class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: list[int], vBars: list[int]) -> int:

        hBars.sort()
        vBars.sort()

        # Longest consecutive horizontal bars
        maxH = curr = 1
        for i in range(1, len(hBars)):
            if hBars[i] == hBars[i - 1] + 1:
                curr += 1
            else:
                curr = 1
            maxH = max(maxH, curr)

        # Longest consecutive vertical bars
        maxV = curr = 1
        for i in range(1, len(vBars)):
            if vBars[i] == vBars[i - 1] + 1:
                curr += 1
            else:
                curr = 1
            maxV = max(maxV, curr)

        side = min(maxH, maxV) + 1
        return side * side

"""
🧠 Why this works:
- k consecutive removed bars → gap of k+1
- Square limited by smaller dimension
- Elegant greedy + sorting
"""
