import java.util.*;

class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {

        Arrays.sort(hBars);
        Arrays.sort(vBars);

        // Longest consecutive horizontal bars
        int maxH = 1, curr = 1;
        for (int i = 1; i < hBars.length; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxH = Math.max(maxH, curr);
        }

        // Longest consecutive vertical bars
        int maxV = 1;
        curr = 1;
        for (int i = 1; i < vBars.length; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxV = Math.max(maxV, curr);
        }

        int side = Math.min(maxH, maxV) + 1;
        return side * side;
    }
}

/*
💡 Notes:
- Sorting enables linear scan
- No grid simulation needed
- Greedy works because constraints are small
*/
