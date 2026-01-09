# Day 09 – Smallest Subtree with All the Deepest Nodes  
🟡 **Difficulty:** Medium

🔗 **Problem Link:**  
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09

---

## 📌 Problem Statement (Simplified)

You are given the **root of a binary tree**.

Some nodes in the tree are at the **maximum depth** (deepest level).

Your task is to find the **smallest subtree** that contains **all the deepest nodes**.

- The subtree must be a **connected part** of the tree
- You must return the **root of that subtree**

---

## 🧠 Prerequisites (Basics You Must Know)

Before solving this problem, you should be comfortable with:

### 🔹 Binary Tree Basics
- Root, left child, right child
- Height and depth of a tree
- Subtrees

### 🔹 Tree Depth
- **Depth of a node** = number of edges from root to that node
- **Maximum depth** = deepest level in the tree

### 🔹 Traversal Techniques
- Depth-First Search (DFS)
- Postorder traversal
- Recursion

📌 This problem is all about **understanding depth correctly**.

---

## ❓ Why This Problem Is Medium

- You must identify **deepest nodes**
- Then determine their **lowest common ancestor**
- Requires combining **depth calculation + subtree logic**
- Needs clean recursion and careful return values

This problem tests:
- Tree recursion skills
- Ability to return **multiple pieces of information** from DFS

---

## ❌ Brute Force Approach (Not Ideal)

### 🔹 Idea
1. Find all deepest nodes
2. For each deepest node, store path to root
3. Find the lowest common ancestor (LCA) of all deepest nodes

### ❌ Why This Is Not Ideal
- Requires extra storage
- Multiple traversals
- More complex logic

📌 Works, but unnecessarily complicated.

---

## 🧠 Key Insight (Turning Point)

The **smallest subtree containing all deepest nodes** is simply:

👉 The **Lowest Common Ancestor (LCA)** of all deepest nodes.

But instead of explicitly finding LCA, we can **compute it naturally using DFS**.

---

## 🧠 Optimal DFS Strategy (Single Pass)

We use DFS that returns **two things** for every node:
1. The **maximum depth** of the subtree
2. The **node that represents the smallest subtree** for deepest nodes

---

## 🧩 DFS Logic (Core Idea)

For each node:
- Compute depth of left subtree
- Compute depth of right subtree

### Three Cases:

1️⃣ **Left depth > Right depth**  
→ Deepest nodes are in left subtree  
→ Return left result

2️⃣ **Right depth > Left depth**  
→ Deepest nodes are in right subtree  
→ Return right result

3️⃣ **Left depth == Right depth**  
→ Deepest nodes exist in both subtrees  
→ Current node is the answer

---

## 🧾 DFS Return Definition

Each DFS call returns:
```cpp
(depth, node)
```

Where:
- `depth` = max depth from this node
- `node` = root of smallest subtree containing deepest nodes

---

## 🧾 Pseudocode (Optimal)
```cpp
function dfs(node):
if node is null:
return (0, null)

leftDepth, leftNode = dfs(node.left)
rightDepth, rightNode = dfs(node.right)

if leftDepth > rightDepth:
    return (leftDepth + 1, leftNode)
else if rightDepth > leftDepth:
    return (rightDepth + 1, rightNode)
else:
    return (leftDepth + 1, node)

return dfs(root).node

```

---

## 🧪 Dry Run Example

### Input Tree
```cpp
    3
   / \
  5   1
 /     \
6       8
```

### Deepest Nodes
- `6` and `8` (depth = 3)

### DFS Analysis
- Node `6` → depth 1
- Node `8` → depth 1
- At node `3`, left depth == right depth

👉 **Answer = 3**

---

## ⚠️ Edge Cases to Consider

- Tree with only one node
- Skewed tree (all left or all right)
- Only one deepest node
- Multiple deepest nodes at same level

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n)`
  - Each node visited once
- **Space Complexity:** `O(n)`
  - Recursion stack (worst case)

This is optimal.

---

## 🧠 What This Problem Teaches

- Returning multiple values from DFS
- Understanding subtree depth
- How LCA logic emerges naturally
- Writing clean recursive tree solutions

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal DFS solution is ACTIVE**
- 📝 **Brute force idea explained, not used**
- 💬 Code is **human-readable and beginner-friendly**
- 🎯 Same clean style as previous tree problems

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)


