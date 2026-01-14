import java.util.*;

class Solution {

    // Segment Tree to maintain UNION width on X-axis
    static class SegmentTree {
        int n;
        int[] xs;
        int[] coverCount;
        int[] coverWidth;

        SegmentTree(int[] xs) {
            this.xs = xs;
            this.n = xs.length - 1;
            this.coverCount = new int[4 * n];
            this.coverWidth = new int[4 * n];
        }

        void add(int l, int r, int val) {
            add(0, 0, n - 1, l, r, val);
        }

        int getCoveredWidth() {
            return coverWidth[0];
        }

        private void add(int idx, int lo, int hi, int l, int r, int val) {
            if (r <= xs[lo] || xs[hi + 1] <= l)
                return;

            if (l <= xs[lo] && xs[hi + 1] <= r) {
                coverCount[idx] += val;
            } else {
                int mid = (lo + hi) / 2;
                add(2 * idx + 1, lo, mid, l, r, val);
                add(2 * idx + 2, mid + 1, hi, l, r, val);
            }

            if (coverCount[idx] > 0) {
                coverWidth[idx] = xs[hi + 1] - xs[lo];
            } else if (lo == hi) {
                coverWidth[idx] = 0;
            } else {
                coverWidth[idx] =
                        coverWidth[2 * idx + 1] + coverWidth[2 * idx + 2];
            }
        }
    }

    public double separateSquares(int[][] squares) {

        List<int[]> events = new ArrayList<>();
        TreeSet<Integer> xsSet = new TreeSet<>();

        // Build events
        for (int[] sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            events.add(new int[]{y, 1, x, x + l});       // enter
            events.add(new int[]{y + l, -1, x, x + l});  // exit
            xsSet.add(x);
            xsSet.add(x + l);
        }

        // Sort events by Y
        events.sort(Comparator.comparingInt(a -> a[0]));

        // Coordinate compression
        int[] xs = xsSet.stream().mapToInt(Integer::intValue).toArray();

        long totalArea = computeTotalArea(events, xs);
        double half = totalArea / 2.0;

        SegmentTree tree = new SegmentTree(xs);

        long currArea = 0;
        int prevY = events.get(0)[0];

        // Sweep line
        for (int[] e : events) {
            int y = e[0], delta = e[1], xl = e[2], xr = e[3];

            int width = tree.getCoveredWidth();
            long areaGain = (long) (y - prevY) * width;

            if (currArea + areaGain >= half) {
                return prevY + (half - currArea) / width;
            }

            currArea += areaGain;
            tree.add(xl, xr, delta);
            prevY = y;
        }

        return prevY;
    }

    private long computeTotalArea(List<int[]> events, int[] xs) {
        SegmentTree tree = new SegmentTree(xs);
        long area = 0;
        int prevY = events.get(0)[0];

        for (int[] e : events) {
            int y = e[0], delta = e[1], xl = e[2], xr = e[3];
            area += (long) (y - prevY) * tree.getCoveredWidth();
            tree.add(xl, xr, delta);
            prevY = y;
        }
        return area;
    }
}
