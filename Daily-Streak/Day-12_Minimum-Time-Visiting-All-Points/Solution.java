class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        // ✅ OPTIMAL GREEDY APPROACH (ACTIVE)
        int time = 0;

        for (int i = 1; i < points.length; i++) {
            int dx = Math.abs(points[i][0] - points[i - 1][0]);
            int dy = Math.abs(points[i][1] - points[i - 1][1]);

            // Use diagonal moves wherever possible
            time += Math.max(dx, dy);
        }

        return time;
    }

    /*
    ===========================
    🧠 MATHEMATICAL INSIGHT (COMMENTED)
    ===========================
    - Minimum time between two points:
      max(|x2-x1|, |y2-y1|)

    ===========================
    ❌ STEP-BY-STEP SIMULATION (COMMENTED)
    ===========================
    - Move one unit per second
    - Valid but inefficient

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    public static void main(String[] args) {
        int[][] points = {{1,1},{3,4},{-1,0}};
        Solution s = new Solution();
        System.out.println(s.minTimeToVisitAllPoints(points));
    }
    */
}
