# Day 05 – Maximum Matrix Sum  
🟡 **Difficulty:** Medium

🔗 **Problem Link:**  
https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

---

## 📌 Problem Statement (Simplified)

You are given a square matrix `matrix` of size `n × n`.

You can perform the following operation **any number of times**:
- Choose **any element** and multiply it by `-1` (i.e., flip its sign).

Your task is to return the **maximum possible sum of all elements** in the matrix after performing optimal operations.

---

## 🧠 Prerequisites (Must Know Before Solving)

Before solving this problem, you should be comfortable with:

### 🔹 Programming Basics
- Nested loops
- Conditional checks
- Using variables to track counts and sums

### 🔹 Mathematical Concepts
- Absolute values
- Positive vs negative numbers
- Even / odd counts
- Greedy decision making

### 🔹 DSA Concepts
- Greedy algorithms
- Observation-based optimization
- Avoiding unnecessary operations

---

## ❓ Why This Problem Is Medium

At first glance, flipping signs looks trivial.  
But the challenge lies in **deciding which signs to flip** to **maximize the total sum**.

This problem tests:
- Your ability to **observe patterns**
- Apply **greedy logic**
- Reduce a problem to **simple mathematical conditions**

---

## ❌ Approach 1: Brute Force (Not Practical)

### 🔹 Idea
- Try flipping different combinations of elements
- Compute sum for each configuration
- Track maximum

### ❌ Why This Fails
- Each element has 2 states (+ / −)
- Total combinations = `2^(n×n)`
- Impossible even for small matrices

📌 **Rejected due to exponential complexity**

---

## 🧠 Key Observation (Turning Point)

Since we can flip **any element any number of times**:

👉 The **sign itself doesn’t matter**, only the **absolute value** does.

So naturally:
- We want **all numbers to be positive**
- But there is **one important constraint**…

---

## 🔑 Core Insight (Very Important)

- If the **count of negative numbers is even**:
  - We can flip signs so that **all elements become positive**
- If the **count of negative numbers is odd**:
  - One element **must remain negative**
  - To minimize loss, that should be the element with the **smallest absolute value**

---

## ✅ Optimal Greedy Approach (USED)

### 🔹 Strategy
1. Take **absolute value** of every element
2. Compute:
   - Total sum of absolute values
   - Count of negative elements
   - Minimum absolute value in the matrix
3. Apply rule:
   - If negatives are even → return total sum
   - If negatives are odd → subtract `2 × minAbs`

---

## 🧾 Pseudocode (Optimal)

```cpp
totalSum = 0
negCount = 0
minAbs = infinity

for each element x in matrix:
if x < 0:
negCount++
totalSum += abs(x)
minAbs = min(minAbs, abs(x))

if negCount is even:
return totalSum
else:
return totalSum - 2 * minAbs
```


---

## 🧪 Dry Run Example

### Example 1

```cpp
matrix = [[1, -1],
[-1, 1]]

Absolute values → [1, 1, 1, 1]
totalSum = 4
negCount = 2 (even)

Answer = 4
```


---

### Example 2

```cpp
matrix = [[-1, 2],
[3, 4]]

Absolute values → [1, 2, 3, 4]
totalSum = 10
negCount = 1 (odd)
minAbs = 1

Answer = 10 - 2*1 = 8
```


---

## ⚠️ Edge Cases to Consider

- Matrix with all positive numbers
- Matrix with all negative numbers
- Single element matrix
- Presence of zero (absolute min becomes 0 → no loss)

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)` extra space

Optimal and efficient.

---

## 🧠 What This Problem Teaches

- Greedy thinking beats brute force
- Absolute values simplify sign problems
- Importance of parity (even/odd)
- Turning operations-based problems into math problems

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal greedy solution is ACTIVE**
- 📝 **Brute force / naive ideas are COMMENTED**
- 💬 Code is **human-readable and beginner-friendly**
- 🎯 Interview-ready logic only

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)
