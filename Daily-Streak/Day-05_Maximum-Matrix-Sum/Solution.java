class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long totalSum = 0;
        int negCount = 0;
        int minAbs = Integer.MAX_VALUE;

        // ✅ OPTIMAL GREEDY APPROACH (ACTIVE CODE)
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                int val = matrix[i][j];

                if (val < 0) negCount++;

                totalSum += Math.abs(val);
                minAbs = Math.min(minAbs, Math.abs(val));
            }
        }

        if (negCount % 2 == 1) {
            totalSum -= 2L * minAbs;
        }

        return totalSum;
    }

    /*
    ===========================
    ❌ NAIVE IDEA (COMMENTED)
    ===========================
    - Try flipping every element independently
    - Track maximum sum
    - Too many combinations → TLE

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    public static void main(String[] args) {
        int[][] matrix = {
            {1, -1},
            {-1, 1}
        };

        long totalSum = 0;
        int negCount = 0;
        int minAbs = Integer.MAX_VALUE;

        for (int[] row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                totalSum += Math.abs(val);
                minAbs = Math.min(minAbs, Math.abs(val));
            }
        }

        if (negCount % 2 == 1) {
            totalSum -= 2L * minAbs;
        }

        System.out.println(totalSum);
    }
    */
}
