/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // ✅ OPTIMAL APPROACH: BFS (Level Order Traversal)

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int answerLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty()) {
            int size = q.size();
            long long currentSum = 0;

            // Process all nodes of current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentSum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Update max sum and level
            if (currentSum > maxSum) {
                maxSum = currentSum;
                answerLevel = level;
            }

            level++;
        }

        return answerLevel;
    }

    /*
    ===========================
    ❌ DFS APPROACH (COMMENTED)
    ===========================
    - Use DFS and track depth
    - Store sums in map or vector
    - More bookkeeping required
    - BFS is cleaner for level-based problems

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(7);
        root->right = new TreeNode(0);
        root->left->left = new TreeNode(7);
        root->left->right = new TreeNode(-8);

        Solution s;
        cout << s.maxLevelSum(root) << endl;
        return 0;
    }
    */
};
