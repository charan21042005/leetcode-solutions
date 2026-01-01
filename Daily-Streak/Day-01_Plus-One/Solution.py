class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)

        # Traverse from the last digit
        for i in range(n - 1, -1, -1):
            digits[i] += 1

            # If no carry, return immediately
            if digits[i] < 10:
                return digits

            # Carry case
            digits[i] = 0

        # If all digits were 9, add 1 at the beginning
        return [1] + digits
