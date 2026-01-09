/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function returns pair:
    // {maximum depth from this node, subtree root containing deepest nodes}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) {
            return {0, nullptr};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If left subtree is deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        // If right subtree is deeper
        else if (right.first > left.first) {
            return {right.first + 1, right.second};
        }
        // If both sides have equal depth
        else {
            return {left.first + 1, root};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // ✅ OPTIMAL DFS APPROACH (ACTIVE)
        return dfs(root).second;
    }

    /*
    ===========================
    ❌ BRUTE FORCE IDEA (COMMENTED)
    ===========================
    - Find all deepest nodes
    - Compute LCA of all deepest nodes
    - Multiple traversals + extra storage

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->right = new TreeNode(1);
        root->left->left = new TreeNode(6);
        root->right->right = new TreeNode(8);

        Solution s;
        TreeNode* ans = s.subtreeWithAllDeepest(root);
        cout << ans->val << endl;
        return 0;
    }
    */
};
