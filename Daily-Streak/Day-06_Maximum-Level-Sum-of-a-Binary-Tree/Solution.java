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
    public int maxLevelSum(TreeNode root) {
        // ✅ OPTIMAL APPROACH: BFS

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        int level = 1;
        int answerLevel = 1;
        long maxSum = Long.MIN_VALUE;

        while (!queue.isEmpty()) {
            int size = queue.size();
            long currentSum = 0;

            // Process current level
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                currentSum += node.val;

                if (node.left != null)  queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }

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
    - Track depth manually
    - Use HashMap<Integer, Integer> for sums
    - More complex than BFS

    ===========================
    🧪 STANDALONE VERSION (COMMENTED)
    ===========================
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(7);
        root.right = new TreeNode(0);
        root.left.left = new TreeNode(7);
        root.left.right = new TreeNode(-8);

        Solution s = new Solution();
        System.out.println(s.maxLevelSum(root));
    }
    */
}
