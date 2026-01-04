class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        answer = 0

        # ✅ OPTIMAL APPROACH (ACTIVE CODE)
        for x in nums:
            count = 0
            total = 0
            i = 1

            while i * i <= x:
                if x % i == 0:
                    d1 = i
                    d2 = x // i

                    count += 1
                    total += d1

                    if d1 != d2:
                        count += 1
                        total += d2

                    # Early stopping
                    if count > 4:
                        break
                i += 1

            if count == 4:
                answer += total

        return answer

        """
        ❌ BRUTE FORCE APPROACH (COMMENTED)

        ans = 0
        for x in nums:
            divisors = []
            for i in range(1, x + 1):
                if x % i == 0:
                    divisors.append(i)
            if len(divisors) == 4:
                ans += sum(divisors)
        return ans

        Reason:
        - Extremely slow
        - Not scalable
        """
