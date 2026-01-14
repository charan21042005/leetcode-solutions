class SegmentTree {
public:
    explicit SegmentTree(const vector<int>& xs)
        : xs(xs), n(xs.size() - 1),
          coveredCount(4 * n), coveredWidth(4 * n) {}

    void add(int l, int r, int val) {
        add(0, 0, n - 1, l, r, val);
    }

    int getCoveredWidth() const {
        return coveredWidth[0];
    }

private:
    int n;
    vector<int> xs;
    vector<int> coveredCount;
    vector<int> coveredWidth;

    void add(int idx, int lo, int hi, int l, int r, int val) {
        if (r <= xs[lo] || xs[hi + 1] <= l)
            return;

        if (l <= xs[lo] && xs[hi + 1] <= r) {
            coveredCount[idx] += val;
        } else {
            int mid = (lo + hi) / 2;
            add(2 * idx + 1, lo, mid, l, r, val);
            add(2 * idx + 2, mid + 1, hi, l, r, val);
        }

        if (coveredCount[idx] > 0) {
            coveredWidth[idx] = xs[hi + 1] - xs[lo];
        } else if (lo == hi) {
            coveredWidth[idx] = 0;
        } else {
            coveredWidth[idx] =
                coveredWidth[2 * idx + 1] + coveredWidth[2 * idx + 2];
        }
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events; // (y, delta, xl, xr)
        set<int> xs;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            events.emplace_back(y, +1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
            xs.insert(x);
            xs.insert(x + l);
        }

        sort(events.begin(), events.end());

        long totalArea = computeTotalArea(events, xs);
        double half = totalArea / 2.0;

        SegmentTree tree(vector<int>(xs.begin(), xs.end()));

        long currArea = 0;
        int prevY = get<0>(events[0]); // ✅ FIX #1

        for (auto& [y, delta, xl, xr] : events) {
            int width = tree.getCoveredWidth();
            long areaGain = (long)(y - prevY) * width;

            if (currArea + areaGain >= half) {
                return prevY + (half - currArea) / width;
            }

            currArea += areaGain;
            tree.add(xl, xr, delta);
            prevY = y;
        }

        return prevY;
    }

private:
    long computeTotalArea(const vector<tuple<int,int,int,int>>& events,
                          const set<int>& xs) {
        SegmentTree tree(vector<int>(xs.begin(), xs.end()));
        long area = 0;
        int prevY = get<0>(events[0]); // ✅ FIX #2

        for (auto& [y, delta, xl, xr] : events) {
            area += (long)(y - prevY) * tree.getCoveredWidth();
            tree.add(xl, xr, delta);
            prevY = y;
        }
        return area;
    }
};
