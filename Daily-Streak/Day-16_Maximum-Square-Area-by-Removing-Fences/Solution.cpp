class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // ✅ OPTIMAL APPROACH:
        // Find the maximum COMMON distance that exists
        // in BOTH horizontal and vertical directions.

        const long long MOD = 1e9 + 7;

        // Add boundary fences (cannot be removed)
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        // Store all possible horizontal distances
        unordered_set<long long> horizontalDistances;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                horizontalDistances.insert(hFences[j] - hFences[i]);
            }
        }

        long long maxSide = -1;

        // Check vertical distances and find common ones
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long dist = vFences[j] - vFences[i];
                if (horizontalDistances.count(dist)) {
                    maxSide = max(maxSide, dist);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (maxSide * maxSide) % MOD;
    }

    /*
    ===========================
    ❌ WRONG IDEA (COMMENTED)
    ===========================
    - Taking only longest consecutive gap
    - Works for similar grid problems
    - FAILS here because square needs
      SAME distance in both directions

    ===========================
    🧪 STANDALONE TEST (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        vector<int> h = {2, 3};
        vector<int> v = {2};
        Solution s;
        cout << s.maximizeSquareArea(4, 3, h, v) << endl; // Expected: 4
        return 0;
    }
    */
};
