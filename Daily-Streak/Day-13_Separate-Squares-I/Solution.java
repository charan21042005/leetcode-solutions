class Solution {
    public double separateSquares(int[][] squares) {
        List<double[]> events = new ArrayList<>();
        double totalArea = 0.0;

        for (int[] sq : squares) {
            double y = sq[1];
            double side = sq[2];
            totalArea += side * side;

            events.add(new double[]{y, +side});
            events.add(new double[]{y + side, -side});
        }

        events.sort(Comparator.comparingDouble(a -> a[0]));

        double target = totalArea / 2.0;
        double currArea = 0.0;
        double currWidth = 0.0;

        for (int i = 0; i + 1 < events.size(); i++) {
            currWidth += events.get(i)[1];
            double y1 = events.get(i)[0];
            double y2 = events.get(i + 1)[0];

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
    ❌ NAIVE APPROACH (COMMENTED)
    ===========================
    - Sorting squares by y
    - Fails on overlaps
    */
}
