# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        # ✅ OPTIMAL APPROACH: BFS

        from collections import deque

        queue = deque([root])
        level = 1
        answer_level = 1
        max_sum = float('-inf')

        while queue:
            size = len(queue)
            current_sum = 0

            # Process one level
            for _ in range(size):
                node = queue.popleft()
                current_sum += node.val

                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            if current_sum > max_sum:
                max_sum = current_sum
                answer_level = level

            level += 1

        return answer_level

        """
        ===========================
        ❌ DFS APPROACH (COMMENTED)
        ===========================
        - Use recursion
        - Maintain dict for level sums
        - BFS is simpler & cleaner

        ===========================
        🧪 STANDALONE VERSION (COMMENTED)
        ===========================
        def main():
            root = TreeNode(1)
            root.left = TreeNode(7)
            root.right = TreeNode(0)
            root.left.left = TreeNode(7)
            root.left.right = TreeNode(-8)

            sol = Solution()
            print(sol.maxLevelSum(root))

        if __name__ == "__main__":
            main()
        """
