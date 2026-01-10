class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] = minimum ASCII delete sum
        // to make s1[i:] and s2[j:] equal
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: s2 exhausted
        for (int i = n - 1; i >= 0; i--) {
            dp[i][m] = dp[i + 1][m] + s1[i];
        }

        // Base case: s1 exhausted
        for (int j = m - 1; j >= 0; j--) {
            dp[n][j] = dp[n][j + 1] + s2[j];
        }

        // Fill DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(
                        s1[i] + dp[i + 1][j],
                        s2[j] + dp[i][j + 1]
                    );
                }
            }
        }

        return dp[0][0];
    }

    /*
    ===========================
    ❌ NAIVE IDEA (COMMENTED)
    ===========================
    - Try deleting characters recursively
    - Compare all possible strings
    - Exponential time → impossible

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        string s1 = "sea";
        string s2 = "eat";

        Solution sol;
        cout << sol.minimumDeleteSum(s1, s2) << endl;
        return 0;
    }
    */
};
