class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        events = []
        total_area = 0.0

        for _, y, side in squares:
            total_area += side * side
            events.append((y, side))
            events.append((y + side, -side))

        events.sort()

        target = total_area / 2.0
        curr_area = 0.0
        curr_width = 0.0

        for i in range(len(events) - 1):
            curr_width += events[i][1]
            y1 = events[i][0]
            y2 = events[i + 1][0]

            if curr_width <= 0:
                continue

            strip_area = (y2 - y1) * curr_width

            if curr_area + strip_area >= target:
                remaining = target - curr_area
                return y1 + remaining / curr_width

            curr_area += strip_area

        return 0.0

        """
        ===========================
        ❌ WRONG LOGIC (COMMENTED)
        ===========================
        - Summing square areas directly
        - Overlaps break correctness
        """
