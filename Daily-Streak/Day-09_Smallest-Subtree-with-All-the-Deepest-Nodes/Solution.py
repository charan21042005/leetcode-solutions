# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        # Helper returns (depth, subtree_root)
        def dfs(node):
            if not node:
                return (0, None)

            left_depth, left_node = dfs(node.left)
            right_depth, right_node = dfs(node.right)

            if left_depth > right_depth:
                return (left_depth + 1, left_node)
            elif right_depth > left_depth:
                return (right_depth + 1, right_node)
            else:
                return (left_depth + 1, node)

        # ✅ OPTIMAL DFS APPROACH (ACTIVE)
        return dfs(root)[1]

        """
        ===========================
        ❌ BRUTE FORCE IDEA (COMMENTED)
        ===========================
        - Find maximum depth
        - Collect deepest nodes
        - Compute LCA manually

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            root = TreeNode(3)
            root.left = TreeNode(5)
            root.right = TreeNode(1)
            root.left.left = TreeNode(6)
            root.right.right = TreeNode(8)

            sol = Solution()
            print(sol.subtreeWithAllDeepest(root).val)

        if __name__ == "__main__":
            main()
        """
