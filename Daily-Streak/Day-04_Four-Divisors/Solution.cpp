class Solution { 
public:
    int sumFourDivisors(vector<int>& nums) {
        int answer = 0;

        // ✅ OPTIMAL APPROACH (ACTIVE CODE)
        for (int x : nums) {
            int count = 0;
            int sum = 0;

            // Check divisors only till sqrt(x)
            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int d1 = i;
                    int d2 = x / i;

                    count++;
                    sum += d1;

                    // If divisor pair is different, count both
                    if (d1 != d2) {
                        count++;
                        sum += d2;
                    }

                    // Early stopping if more than 4 divisors
                    if (count > 4) break;
                }
            }

            // If exactly 4 divisors, add their sum
            if (count == 4) {
                answer += sum;
            }
        }

        return answer;
    }

    /*
    ❌ BRUTE FORCE APPROACH (COMMENTED – FOR LEARNING ONLY)

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            vector<int> divisors;
            for (int i = 1; i <= x; i++) {
                if (x % i == 0) {
                    divisors.push_back(i);
                }
            }
            if (divisors.size() == 4) {
                for (int d : divisors) ans += d;
            }
        }
        return ans;
    }

    Reason for rejection:
    - Very slow (O(n × x))
    - Will TLE for large numbers
    */
};
