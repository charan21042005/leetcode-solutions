class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        // ✅ OPTIMAL APPROACH: Brute Force + Math (Rectangle Intersection)

        int n = bottomLeft.size();
        long long ans = 0;

        // Try all pairs of rectangles
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Compute intersection boundaries
                long long left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long right  = min(topRight[i][0],  topRight[j][0]);
                long long bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long top    = min(topRight[i][1],  topRight[j][1]);

                long long width  = right - left;
                long long height = top - bottom;

                // Valid intersection check
                if (width <= 0 || height <= 0) continue;

                // Largest square inside intersection
                long long side = min(width, height);
                ans = max(ans, side * side);
            }
        }

        return ans;
    }

    /*
    ===============================
    ❌ OVERKILL APPROACH (COMMENTED)
    ===============================
    - Sweep line / geometry trees
    - Too complex for n ≤ 1000
    - Brute force is sufficient

    ===============================
    🧪 STANDALONE TEST (COMMENTED)
    ===============================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        vector<vector<int>> bottomLeft = {{1,1},{2,2},{1,2}};
        vector<vector<int>> topRight   = {{3,3},{4,4},{3,4}};

        Solution s;
        cout << s.largestSquareArea(bottomLeft, topRight) << endl;
        return 0;
    }
    */
};
