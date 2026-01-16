import java.util.*;

class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        // ✅ OPTIMAL APPROACH:
        // Find maximum COMMON distance between
        // horizontal and vertical fence pairs.

        final long MOD = 1_000_000_007L;

        List<Integer> h = new ArrayList<>();
        List<Integer> v = new ArrayList<>();

        for (int x : hFences) h.add(x);
        for (int x : vFences) v.add(x);

        // Add boundary fences
        h.add(1); h.add(m);
        v.add(1); v.add(n);

        Collections.sort(h);
        Collections.sort(v);

        // Store all horizontal distances
        Set<Long> horizontalDistances = new HashSet<>();

        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                horizontalDistances.add((long) h.get(j) - h.get(i));
            }
        }

        long maxSide = -1;

        // Match vertical distances
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                long dist = (long) v.get(j) - v.get(i);
                if (horizontalDistances.contains(dist)) {
                    maxSide = Math.max(maxSide, dist);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (int) ((maxSide * maxSide) % MOD);
    }

    /*
    ===========================
    ❌ WRONG IDEA (COMMENTED)
    ===========================
    - Using only longest gap
    - Ignores requirement that
      BOTH dimensions must match

    ===========================
    🧪 STANDALONE TEST (COMMENTED)
    ===========================
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] h = {2, 3};
        int[] v = {2};
        System.out.println(s.maximizeSquareArea(4, 3, h, v)); // 4
    }
    */
}
