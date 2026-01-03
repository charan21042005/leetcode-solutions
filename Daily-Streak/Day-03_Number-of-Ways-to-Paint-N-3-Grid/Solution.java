class Solution {
    public int numOfWays(int n) {
        final int MOD = 1000000007;

        // same -> ABA pattern count
        // diff -> ABC pattern count
        long same = 6;
        long diff = 6;

        // Process each row from 2 to n
        for (int row = 2; row <= n; row++) {

            // Transition to next row
            long newSame = (same * 3 + diff * 2) % MOD;
            long newDiff = (same * 2 + diff * 2) % MOD;

            // Update values
            same = newSame;
            diff = newDiff;
        }

        // Final answer
        return (int)((same + diff) % MOD);
    }
}
