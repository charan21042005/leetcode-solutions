class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        // ✅ OPTIMAL APPROACH: Brute Force + Math

        int n = bottomLeft.length;
        long ans = 0;

        // Try all rectangle pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Intersection boundaries
                long left   = Math.max(bottomLeft[i][0], bottomLeft[j][0]);
                long right  = Math.min(topRight[i][0],  topRight[j][0]);
                long bottom = Math.max(bottomLeft[i][1], bottomLeft[j][1]);
                long top    = Math.min(topRight[i][1],  topRight[j][1]);

                long width  = right - left;
                long height = top - bottom;

                // Valid intersection
                if (width <= 0 || height <= 0) continue;

                long side = Math.min(width, height);
                ans = Math.max(ans, side * side);
            }
        }

        return ans;
    }

    /*
    ==========================
    🧪 STANDALONE TEST
    ==========================
    public static void main(String[] args) {
        int[][] bottomLeft = {{1,1},{2,2},{1,2}};
        int[][] topRight   = {{3,3},{4,4},{3,4}};

        Solution s = new Solution();
        System.out.println(s.largestSquareArea(bottomLeft, topRight));
    }
    */
}
