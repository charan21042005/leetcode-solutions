class Solution {
    public int sumFourDivisors(int[] nums) {
        int answer = 0;

        // ✅ OPTIMAL APPROACH (ACTIVE CODE)
        for (int x : nums) {
            int count = 0;
            int sum = 0;

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int d1 = i;
                    int d2 = x / i;

                    count++;
                    sum += d1;

                    if (d1 != d2) {
                        count++;
                        sum += d2;
                    }

                    // Stop early if more than 4 divisors
                    if (count > 4) break;
                }
            }

            if (count == 4) {
                answer += sum;
            }
        }

        return answer;
    }

    /*
    ❌ BRUTE FORCE APPROACH (COMMENTED)

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            List<Integer> divisors = new ArrayList<>();
            for (int i = 1; i <= x; i++) {
                if (x % i == 0) {
                    divisors.add(i);
                }
            }
            if (divisors.size() == 4) {
                for (int d : divisors) ans += d;
            }
        }
        return ans;
    }

    Drawback:
    - Too slow
    - Not suitable for large inputs
    */
}
