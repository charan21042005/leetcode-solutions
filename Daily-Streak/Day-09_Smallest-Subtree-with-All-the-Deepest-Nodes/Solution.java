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

    // Helper class to store depth and subtree node
    private static class Pair {
        int depth;
        TreeNode node;

        Pair(int depth, TreeNode node) {
            this.depth = depth;
            this.node = node;
        }
    }

    private Pair dfs(TreeNode root) {
        if (root == null) {
            return new Pair(0, null);
        }

        Pair left = dfs(root.left);
        Pair right = dfs(root.right);

        if (left.depth > right.depth) {
            return new Pair(left.depth + 1, left.node);
        } else if (right.depth > left.depth) {
            return new Pair(right.depth + 1, right.node);
        } else {
            return new Pair(left.depth + 1, root);
        }
    }

    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        // ✅ OPTIMAL DFS APPROACH (ACTIVE)
        return dfs(root).node;
    }

    /*
    ===========================
    ❌ BRUTE FORCE IDEA (COMMENTED)
    ===========================
    - Track depths using map
    - Find deepest nodes
    - Compute LCA separately

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(5);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(6);
        root.right.right = new TreeNode(8);

        Solution s = new Solution();
        System.out.println(s.subtreeWithAllDeepest(root).val);
    }
    */
}
