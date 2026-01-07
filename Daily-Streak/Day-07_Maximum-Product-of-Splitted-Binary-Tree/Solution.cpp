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
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    // First DFS: compute total sum of tree
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second DFS: compute subtree sums & update max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subtreeSum = root->val + leftSum + rightSum;

        // Try splitting here
        long long product = subtreeSum * (totalSum - subtreeSum);
        maxProd = max(maxProd, product);

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        // ✅ OPTIMAL TWO-PASS DFS APPROACH (ACTIVE)
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }

    /*
    ===========================
    ❌ BRUTE FORCE IDEA (COMMENTED)
    ===========================
    - Remove each edge
    - Recompute subtree sums
    - O(n^2) → TLE

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);

        Solution s;
        cout << s.maxProduct(root) << endl;
        return 0;
    }
    */
};
