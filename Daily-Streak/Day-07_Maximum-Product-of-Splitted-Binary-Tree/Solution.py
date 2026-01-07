# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7
        self.total_sum = 0
        self.max_product = 0

        # First DFS: compute total tree sum
        def get_total_sum(node):
            if not node:
                return 0
            return node.val + get_total_sum(node.left) + get_total_sum(node.right)

        # Second DFS: compute subtree sums & update max product
        def dfs(node):
            if not node:
                return 0

            left_sum = dfs(node.left)
            right_sum = dfs(node.right)

            subtree_sum = node.val + left_sum + right_sum

            product = subtree_sum * (self.total_sum - subtree_sum)
            self.max_product = max(self.max_product, product)

            return subtree_sum

        # ✅ OPTIMAL TWO-PASS DFS APPROACH (ACTIVE)
        self.total_sum = get_total_sum(root)
        dfs(root)

        return self.max_product % MOD

        """
        ===========================
        ❌ BRUTE FORCE IDEA (COMMENTED)
        ===========================
        - Try splitting at every edge
        - Recalculate subtree sums
        - O(n^2) → not feasible

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            root = TreeNode(1)
            root.left = TreeNode(2)
            root.right = TreeNode(3)
            root.left.left = TreeNode(4)
            root.left.right = TreeNode(5)

            sol = Solution()
            print(sol.maxProduct(root))

        if __name__ == "__main__":
            main()
        """
