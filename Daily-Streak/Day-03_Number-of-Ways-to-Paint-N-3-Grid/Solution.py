class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7

        # same -> ABA pattern count
        # diff -> ABC pattern count
        same = 6
        diff = 6

        # Build DP row by row
        for _ in range(2, n + 1):

            # Apply transition rules
            new_same = (same * 3 + diff * 2) % MOD
            new_diff = (same * 2 + diff * 2) % MOD

            # Update for next iteration
            same = new_same
            diff = new_diff

        # Total valid colorings
        return (same + diff) % MOD
