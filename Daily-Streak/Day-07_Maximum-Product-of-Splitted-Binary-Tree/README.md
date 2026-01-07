# Day 07 – Maximum Product of Splitted Binary Tree  
🔴 **Difficulty:** Hard

🔗 **Problem Link:**  
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

---

## 📌 Problem Statement (Simplified)

You are given the **root of a binary tree**, where each node contains a **positive integer value**.

You are allowed to **remove exactly one edge** from the tree, which splits the tree into **two non-empty subtrees**.

Your task is to:
- Compute the **sum of values** in each of the two resulting subtrees
- Return the **maximum product** of these two sums

Since the product can be large, return the result **modulo `10⁹ + 7`**.

---

## 🧠 Prerequisites (Must Know Before Solving)

This problem requires comfort with the following concepts:

### 🔹 Tree Basics
- Binary tree structure
- Parent–child relationships
- Subtrees
- Tree traversal

### 🔹 Traversal Techniques
- **Depth-First Search (DFS)**
- Postorder traversal (left → right → node)
- Recursion

### 🔹 Mathematical Concepts
- Sum of elements
- Product maximization
- Modulo arithmetic

### 🔹 DSA Concepts
- Tree DP (dynamic programming on trees)
- Two-pass DFS idea
- Optimizing brute force

📌 If subtree sums and DFS are not clear, this problem will feel very hard.

---

## ❓ Why This Problem Is HARD

- Every possible edge removal creates a different split
- Brute force checking all splits is inefficient
- Requires computing subtree sums correctly
- Needs careful handling of **large numbers**
- Combines **tree traversal + math optimization**

This problem tests:
- Tree intuition
- Postorder DFS understanding
- Ability to separate computation into stages

---

## ❌ Approach 1: Brute Force (Not Practical)

### 🔹 Idea
- For each edge:
  - Remove the edge
  - Compute sum of both subtrees
  - Compute product
- Track maximum product

### ❌ Why This Fails
- Tree has `O(n)` edges
- Each sum computation takes `O(n)`
- Overall complexity: **O(n²)** → too slow

📌 Rejected due to inefficiency.

---

## 🧠 Key Observation (Turning Point)

When we remove **one edge**, we are essentially separating:
- One **subtree**
- The **rest of the tree**

If:
- `subtreeSum` = sum of a subtree
- `totalSum` = sum of all nodes in the tree

Then the product is:
```cpp
subtreeSum × (totalSum − subtreeSum)
```


👉 So the problem reduces to:
> **Find a subtree whose sum maximizes  
> `subtreeSum × (totalSum − subtreeSum)`**

---

## 🧠 Optimal Strategy (Two-Phase DFS)

We solve this problem in **two DFS passes**:

---

### 🔹 Phase 1: Compute Total Tree Sum

- Use DFS to calculate the **sum of all node values**
- Store this as `totalSum`

This is required to compute the second part of the product.

---

### 🔹 Phase 2: Compute Subtree Sums & Max Product

- Use **postorder DFS**
- For each node:
  - Compute sum of its subtree
  - Treat this subtree as one part of the split
  - Compute product:
    ```
    subtreeSum × (totalSum − subtreeSum)
    ```
  - Update maximum product

Why **postorder**?
- Children must be processed before parent
- Subtree sum depends on children

---

## 🧾 Pseudocode (Optimal)
```cpp
MOD = 10^9 + 7
maxProduct = 0

function getTotalSum(node):
if node is null:
return 0
return node.val + getTotalSum(node.left) + getTotalSum(node.right)

function dfs(node):
if node is null:
return 0

leftSum = dfs(node.left)
rightSum = dfs(node.right)

subtreeSum = node.val + leftSum + rightSum

product = subtreeSum * (totalSum - subtreeSum)
maxProduct = max(maxProduct, product)

return subtreeSum

totalSum = getTotalSum(root)
dfs(root)

return maxProduct % MOD

```

---

## 🧪 Dry Run Example

### Input Tree
```cpp
    1
   / \
  2   3
 / \
4   5
```

### Step 1: Total Sum
```cpp
totalSum = 1 + 2 + 3 + 4 + 5 = 15
```

---

### Step 2: Subtree Products

| Subtree Root | Subtree Sum | Other Part | Product |
|-------------|------------|------------|---------|
| 4 | 4 | 11 | 44 |
| 5 | 5 | 10 | 50 |
| 2 | 11 | 4 | 44 |
| 3 | 3 | 12 | 36 |

👉 **Maximum product = 50**

---

## ⚠️ Important Edge Cases

- Tree with only 2 nodes
- Highly skewed tree
- Very large node values
- Overflow risk → use `long long`
- Must return result modulo `10⁹ + 7`

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n)`
  - Each node visited a constant number of times
- **Space Complexity:** `O(n)`
  - Recursion stack in worst case (skewed tree)

This is optimal.

---

## 🧠 What This Problem Teaches

- How to apply DFS on trees effectively
- Postorder traversal importance
- Separating computation into phases
- Converting edge-removal problems into subtree problems
- Handling large numbers safely

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal two-DFS solution is ACTIVE**
- 📝 **Brute force idea explained & commented**
- 💬 Code is **human-readable and interview-friendly**
- 🎯 Follows same clean style as previous days

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)



