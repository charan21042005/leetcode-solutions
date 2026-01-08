class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // dp[i][j] = max dot product using nums1[i:] and nums2[j:]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int take = nums1[i] * nums2[j];
                if (dp[i + 1][j + 1] != INT_MIN) {
                    take += max(0, dp[i + 1][j + 1]);
                }

                int skip1 = dp[i + 1][j];
                int skip2 = dp[i][j + 1];

                dp[i][j] = max({take, skip1, skip2});
            }
        }

        return dp[0][0];
    }

    /*
    ===========================
    ❌ WRONG IDEA (COMMENTED)
    ===========================
    - Initialize dp with 0
    - This allows empty subsequence
    - Fails when all products are negative

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        vector<int> nums1 = {2, 1, -2, 5};
        vector<int> nums2 = {3, 0, -6};

        Solution s;
        cout << s.maxDotProduct(nums1, nums2) << endl;
        return 0;
    }
    */
};
