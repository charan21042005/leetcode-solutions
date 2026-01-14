class SegmentTree:
    def __init__(self, xs):
        self.xs = xs
        self.n = len(xs) - 1
        self.cover = [0] * (4 * self.n)
        self.width = [0] * (4 * self.n)

    def add(self, l, r, val):
        self._add(0, 0, self.n - 1, l, r, val)

    def _add(self, idx, lo, hi, l, r, val):
        if r <= self.xs[lo] or self.xs[hi + 1] <= l:
            return

        if l <= self.xs[lo] and self.xs[hi + 1] <= r:
            self.cover[idx] += val
        else:
            mid = (lo + hi) // 2
            self._add(idx * 2 + 1, lo, mid, l, r, val)
            self._add(idx * 2 + 2, mid + 1, hi, l, r, val)

        if self.cover[idx] > 0:
            self.width[idx] = self.xs[hi + 1] - self.xs[lo]
        elif lo == hi:
            self.width[idx] = 0
        else:
            self.width[idx] = (
                self.width[idx * 2 + 1] + self.width[idx * 2 + 2]
            )

    def get_width(self):
        return self.width[0]


class Solution:
    def separateSquares(self, squares):
        events = []
        xs = set()

        for x, y, l in squares:
            events.append((y, 1, x, x + l))
            events.append((y + l, -1, x, x + l))
            xs.add(x)
            xs.add(x + l)

        events.sort()
        xs = sorted(xs)

        def compute_total_area():
            tree = SegmentTree(xs)
            area = 0
            prev_y = events[0][0]

            for y, delta, xl, xr in events:
                area += (y - prev_y) * tree.get_width()
                tree.add(xl, xr, delta)
                prev_y = y

            return area

        half = compute_total_area() / 2
        tree = SegmentTree(xs)

        curr_area = 0
        prev_y = events[0][0]

        for y, delta, xl, xr in events:
            width = tree.get_width()
            gain = (y - prev_y) * width

            if curr_area + gain >= half:
                return prev_y + (half - curr_area) / width

            curr_area += gain
            tree.add(xl, xr, delta)
            prev_y = y

        return prev_y
