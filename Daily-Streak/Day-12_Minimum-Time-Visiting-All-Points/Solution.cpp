class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // ✅ OPTIMAL GREEDY APPROACH (ACTIVE)
        int time = 0;

        for (int i = 1; i < points.size(); i++) {
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);

            // Diagonal moves cover both x and y together
            time += max(dx, dy);
        }

        return time;
    }

    /*
    ===========================
    🧠 ALTERNATE THINKING (COMMENTED)
    ===========================
    - Each diagonal move reduces both dx and dy by 1
    - Remaining distance is straight moves
    - Total time = max(dx, dy)

    ===========================
    ❌ SIMULATION APPROACH (COMMENTED)
    ===========================
    - Move step by step
    - Simulate diagonal/straight moves
    - Correct but unnecessary

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
        Solution s;
        cout << s.minTimeToVisitAllPoints(points) << endl;
        return 0;
    }
    */
};
