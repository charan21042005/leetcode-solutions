# Day 08 – Max Dot Product of Two Subsequences  
🔴 **Difficulty:** Hard

🔗 **Problem Link:**  
https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08

---

## 📌 Problem Statement (Simplified)

You are given two integer arrays:
- `nums1`
- `nums2`

You must choose **non-empty subsequences** from both arrays (not necessarily contiguous).

Your goal is to **maximize the dot product** of the two chosen subsequences.

### Dot Product Definition
```cpp
If:
A = [a1, a2, ..., ak]
B = [b1, b2, ..., bk]

Then:
dotProduct = a1b1 + a2b2 + ... + ak*bk

Return the **maximum possible dot product**.
```
---

## 🧠 Prerequisites (Very Important)

Before attempting this problem, you should understand:

### 🔹 Subsequence Basics
- A subsequence **keeps order**
- You can skip elements
- Subsequence must be **non-empty**

Example:
```cpp
[1, 2, 3] → subsequence: [1, 3]
```

---

### 🔹 Dynamic Programming (DP)
- Defining states clearly
- Transition logic
- Handling overlapping subproblems

---

### 🔹 Handling Negative Numbers
This problem is tricky because:
- Arrays may contain **negative values**
- Sometimes choosing a **single pair** gives the best result
- Empty subsequence is **not allowed**

📌 Many DP solutions fail because they incorrectly allow empty subsequences.

---

## ❓ Why This Problem Is HARD

- Combines **2D DP + subsequences**
- Negative values break greedy logic
- Empty subsequence is NOT allowed
- Requires careful base-case handling
- DP transitions are not obvious

This problem tests:
- DP state design
- Edge-case awareness
- Mathematical reasoning with negatives

---

## ❌ Naive / Brute Force Approach (Impossible)

### 🔹 Idea
- Generate all subsequences of `nums1`
- Generate all subsequences of `nums2`
- Compute dot product for matching lengths

### ❌ Why This Fails
- Number of subsequences = `2^n`
- Completely infeasible

📌 **Rejected immediately**

---

## 🧠 Key Insight (Turning Point)

We must decide **for each index**:
- Take the current elements from both arrays
- Or skip one element
- Or skip both

This screams **Dynamic Programming**.

---

## 🧠 DP State Definition (MOST IMPORTANT PART)
```cpp
Let:
dp[i][j] = maximum dot product using:
nums1[i:] and nums2[j:]
```

Meaning:
- We are deciding from index `i` in `nums1`
- And index `j` in `nums2`

---

## ⚠️ Critical Rule (Why Many Solutions Fail)

👉 **We must pick at least ONE pair.**

So:
- We cannot initialize DP with `0`
- Because `0` could represent “pick nothing”
- But empty subsequence is **not allowed**

### ✅ Solution
We initialize DP values to **very negative numbers** (`-infinity`).

This forces the DP to **pick at least one pair**.

---

## 🔁 DP Transitions (Core Logic)

At position `(i, j)` we have **three choices**:

---

### ✅ Choice 1: Take both elements
```cpp
nums1[i] * nums2[j] + max(0, dp[i+1][j+1])
```

Why `max(0, ...)`?
- If future contribution is negative, better to stop
- Ensures we can pick **just one pair**

---

### ❌ Choice 2: Skip element from nums1
```cpp
dp[i+1][j]
```

---

### ❌ Choice 3: Skip element from nums2
```cpp
dp[i][j+1]
```

---

### ✅ Final Transition
```cpp
dp[i][j] = max(
nums1[i] * nums2[j] + max(0, dp[i+1][j+1]),
dp[i+1][j],
dp[i][j+1]
)
```

---

## 🧾 Pseudocode (Bottom-Up DP)
```cpp
Initialize dp array with very small negative values

for i from n-1 down to 0:
for j from m-1 down to 0:
take = nums1[i] * nums2[j] + max(0, dp[i+1][j+1])
skip1 = dp[i+1][j]
skip2 = dp[i][j+1]
    dp[i][j] = max(take, skip1, skip2)

return dp[0][0]
```

---

## 🧪 Dry Run Example

### Input
```cpp
nums1 = [2, 1, -2, 5]
nums2 = [3, 0, -6]
```
Best choice:
```cpp
[2, 5] and [3, -6]
Dot product = 23 + 5(-6) = 6 - 30 = -24 ❌
```

Better:
```cpp
[1, -2] and [3, -6]
Dot product = 13 + (-2)(-6) = 3 + 12 = 15 ✅
```

DP ensures all such combinations are explored optimally.

---

## ⚠️ Important Edge Cases

- All values negative
- One array size = 1
- Best answer is a **single pair**
- Mixed positive and negative values

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n × m)`
- **Space Complexity:** `O(n × m)`

Where:
- `n = len(nums1)`
- `m = len(nums2)`

---

## 🧠 What This Problem Teaches

- Advanced DP state design
- Handling constraints like “non-empty subsequence”
- Why initializing DP properly matters
- Combining math intuition with DP

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal DP solution is ACTIVE**
- 📝 **Naive ideas explained, not used**
- 💬 Code is **human-readable and interview-friendly**
- 🎯 Same clean style as previous HARD problems

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)








