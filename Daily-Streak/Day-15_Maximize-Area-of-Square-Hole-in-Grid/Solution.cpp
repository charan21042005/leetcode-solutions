class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        // Sort removable bars
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // Find longest consecutive run in horizontal bars
        int maxH = 1, curr = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxH = max(maxH, curr);
        }

        // Find longest consecutive run in vertical bars
        int maxV = 1;
        curr = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxV = max(maxV, curr);
        }

        // Side length of largest square hole
        int side = min(maxH, maxV) + 1;

        return side * side;
    }
};

/*
🧪 Standalone intuition:
- Removing k consecutive bars creates a gap of size k+1
- Square side limited by smaller of horizontal & vertical gaps
*/
