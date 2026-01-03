class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        // Base case:
        // same -> ABA type patterns in one row
        // diff -> ABC type patterns in one row
        long long same = 6;
        long long diff = 6;

        // Build the solution row by row
        for (int row = 2; row <= n; row++) {

            // Calculate new values using transition rules
            long long newSame = (same * 3 + diff * 2) % MOD;
            long long newDiff = (same * 2 + diff * 2) % MOD;

            // Update states for next iteration
            same = newSame;
            diff = newDiff;
        }

        // Total ways = same + diff
        return (same + diff) % MOD;
    }
};
