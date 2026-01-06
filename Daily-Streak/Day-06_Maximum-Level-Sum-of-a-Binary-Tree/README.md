# Day 06 – Maximum Level Sum of a Binary Tree  
🟡 **Difficulty:** Medium

🔗 **Problem Link:**  
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06

---

## 📌 Problem Statement (Simplified)

You are given the **root of a binary tree**.

Each node contains an integer value (can be positive, negative, or zero).

Your task is to:
- Calculate the **sum of values at each level** of the tree
- Return the **level number (1-indexed)** that has the **maximum sum**

If there are multiple levels with the same maximum sum, return the **smallest level number**.

---

## 🧠 Prerequisites (Basics You Must Know)

Before solving this problem, you should be comfortable with:

### 🔹 Tree Basics
- What is a **binary tree**
- Root, left child, right child
- Height and levels of a tree

### 🔹 Traversal Techniques
- **Breadth-First Search (BFS)**
- Level-order traversal
- Using a **queue** to process nodes level by level

### 🔹 Programming Concepts
- Loops
- Conditional checks
- Tracking maximum values
- Using counters and sums

📌 If BFS and level-order traversal are not clear, this problem will feel confusing.

---

## ❓ Why This Problem Is Medium

- Tree traversal is required
- Values can be **negative**
- You must correctly track **level numbers**
- Need to compare sums across multiple levels

This problem tests:
- Understanding of **BFS**
- Correct **level handling**
- Clean implementation without off-by-one errors

---

## ❌ Approach 1: DFS with Depth Tracking (Not Preferred)

### 🔹 Idea
- Traverse the tree using DFS
- Keep track of depth
- Store sums in a map or array

### ❌ Why Not Ideal
- Extra space needed for map/array
- Slightly more complex to manage depth
- BFS is more natural for level-based problems

📌 This approach works, but is **not the best choice here**.

---

## ✅ Key Observation (Turning Point)

This is a **level-based problem**, so:

👉 **Level-order traversal (BFS)** is the most natural and clean solution.

Why?
- BFS processes nodes **level by level**
- We can easily calculate the sum for each level
- Level number is automatically tracked

---

## 🧠 Optimal Approach: Breadth-First Search (BFS)

### 🔹 Strategy
1. Use a **queue**
2. Push the root node
3. For each level:
   - Process all nodes currently in the queue
   - Sum their values
   - Push their children into the queue
4. Compare the current level sum with the maximum sum seen so far
5. Track the level number

---

## 🧾 Pseudocode (Optimal)

```cpp
if root is null:
return 0

queue = empty queue
push root into queue

level = 1
maxSum = -infinity
answerLevel = 1

while queue is not empty:
size = queue.size()
currentSum = 0

for i from 1 to size:
    node = queue.pop()
    currentSum += node.val

    if node.left exists:
        push node.left
    if node.right exists:
        push node.right

if currentSum > maxSum:
    maxSum = currentSum
    answerLevel = level

level++

return answerLevel
```

---

## 🧪 Dry Run Example

### Input Tree
```cpp
    1
   / \
  7   0
 / \
7  -8
```


### Level-wise Calculation

**Level 1:**  
```cpp
Nodes → [1]  
Sum = 1  
Max so far = 1 (answer = 1)
```

**Level 2:**  
```cpp
Nodes → [7, 0]  
Sum = 7  
Max so far = 7 (answer = 2)
```

**Level 3:**  
```cpp
Nodes → [7, -8]  
Sum = -1  
Max remains = 7
```

### Final Answer
```cpp
2
```


---

## ⚠️ Edge Cases to Consider

- Tree with only one node
- Tree with all negative values
- Tree with multiple levels having same sum
- Very deep tree (ensure BFS is efficient)

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n)`
  - Every node is visited once
- **Space Complexity:** `O(n)`
  - Queue can hold up to one level of nodes

This is optimal.

---

## 🧠 What This Problem Teaches

- How to apply BFS effectively
- Level-order traversal use cases
- Handling negative values carefully
- Clean separation of logic and state tracking
- Choosing the **right traversal for the problem**

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal BFS solution is ACTIVE**
- 📝 **Other approaches (DFS idea) are COMMENTED**
- 💬 Code is **human-readable and beginner-friendly**
- 🎯 Interview-ready implementation

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)


