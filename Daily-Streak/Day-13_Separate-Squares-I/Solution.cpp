class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // Each event: (y, delta_width)
        vector<pair<double, double>> events;
        double totalArea = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double side = sq[2];
            totalArea += side * side;

            events.push_back({y, +side});         // square starts
            events.push_back({y + side, -side});  // square ends
        }

        sort(events.begin(), events.end());

        double target = totalArea / 2.0;
        double currArea = 0.0;
        double currWidth = 0.0;

        for (int i = 0; i + 1 < events.size(); i++) {
            currWidth += events[i].second;
            double y1 = events[i].first;
            double y2 = events[i + 1].first;

            if (currWidth <= 0) continue;

            double stripArea = (y2 - y1) * currWidth;

            if (currArea + stripArea >= target) {
                double remaining = target - currArea;
                return y1 + remaining / currWidth;
            }

            currArea += stripArea;
        }

        return 0.0;
    }

    /*
    ===========================
    ❌ WRONG IDEA (COMMENTED)
    ===========================
    - Adding square areas directly
    - Ignores vertical overlaps
    */
};
