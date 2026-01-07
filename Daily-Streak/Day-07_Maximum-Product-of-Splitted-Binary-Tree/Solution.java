/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private long totalSum = 0;
    private long maxProduct = 0;
    private final int MOD = 1000000007;

    // First DFS: total tree sum
    private long getTotalSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + getTotalSum(root.left) + getTotalSum(root.right);
    }

    // Second DFS: subtree sums & max product
    private long dfs(TreeNode root) {
        if (root == null) return 0;

        long leftSum = dfs(root.left);
        long rightSum = dfs(root.right);

        long subtreeSum = root.val + leftSum + rightSum;

        long product = subtreeSum * (totalSum - subtreeSum);
        maxProduct = Math.max(maxProduct, product);

        return subtreeSum;
    }

    public int maxProduct(TreeNode root) {
        // ✅ OPTIMAL TWO-PASS DFS APPROACH (ACTIVE)
        totalSum = getTotalSum(root);
        dfs(root);
        return (int)(maxProduct % MOD);
    }

    /*
    ===========================
    ❌ NAIVE EDGE-REMOVAL IDEA (COMMENTED)
    ===========================
    - Remove edge
    - Compute sums repeatedly
    - Very slow

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        Solution s = new Solution();
        System.out.println(s.maxProduct(root));
    }
    */
}
