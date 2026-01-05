class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        // ✅ OPTIMAL GREEDY APPROACH (ACTIVE CODE)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int val = matrix[i][j];

                if (val < 0) negCount++;

                totalSum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        // If negative count is odd, one smallest abs value must stay negative
        if (negCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }

    /*
    ===========================
    ❌ BRUTE FORCE IDEA (COMMENTED)
    ===========================
    - Try flipping combinations of signs
    - Compute all possible sums
    - Exponential complexity: 2^(n*n)
    - Completely impractical

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        vector<vector<int>> matrix = {
            {1, -1},
            {-1, 1}
        };

        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                totalSum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        if (negCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        cout << totalSum << endl;
        return 0;
    }
    */
};
