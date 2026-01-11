class Solution {
public:
    // Helper: Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // ✅ OPTIMAL APPROACH: Histogram + Monotonic Stack
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxRectangle = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(heights));
        }

        return maxRectangle;
    }

    /*
    ===========================
    ❌ BRUTE FORCE IDEA (COMMENTED)
    ===========================
    - Try all possible rectangles
    - Check if all cells are '1'
    - O(n^3) or worse → TLE

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    int main() {
        vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
        };
        Solution s;
        cout << s.maximalRectangle(matrix) << endl;
        return 0;
    }
    */
};
