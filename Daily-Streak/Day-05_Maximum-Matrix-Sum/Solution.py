class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum = 0
        neg_count = 0
        min_abs = float('inf')

        # ✅ OPTIMAL GREEDY APPROACH (ACTIVE CODE)
        for row in matrix:
            for val in row:
                if val < 0:
                    neg_count += 1

                total_sum += abs(val)
                min_abs = min(min_abs, abs(val))

        if neg_count % 2 == 1:
            total_sum -= 2 * min_abs

        return total_sum

        """
        ===========================
        ❌ BRUTE FORCE IDEA (COMMENTED)
        ===========================
        - Try flipping each element sign
        - Track maximum possible sum
        - Exponential combinations → impossible

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            matrix = [
                [1, -1],
                [-1, 1]
            ]

            total_sum = 0
            neg_count = 0
            min_abs = float('inf')

            for row in matrix:
                for val in row:
                    if val < 0:
                        neg_count += 1
                    total_sum += abs(val)
                    min_abs = min(min_abs, abs(val))

            if neg_count % 2 == 1:
                total_sum -= 2 * min_abs

            print(total_sum)

        if __name__ == "__main__":
            main()
        """
