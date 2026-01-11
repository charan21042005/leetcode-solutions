# Day 11 – Maximal Rectangle  
🔴 **Difficulty:** Hard

🔗 **Problem Link:**  
https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11

---

## 📌 Problem Statement (Simplified)

You are given a **binary matrix** consisting of characters `'0'` and `'1'`.

Your task is to find the **largest rectangle containing only `'1'`s** and return its **area**.

- Rectangle sides must be **parallel to the matrix axes**
- Rectangle must be **continuous**

---

## 🧠 Prerequisites (VERY IMPORTANT)

Before solving this problem, you must understand:

### 🔹 Matrix Basics
- Rows and columns
- Iterating row by row
- Binary matrices (`0` / `1`)

### 🔹 Histogram Concept
- Bars with heights
- Rectangle area = `height × width`
- Largest rectangle in histogram

### 🔹 Stack (Monotonic Stack)
- Stack that maintains **increasing heights**
- Used to find **previous smaller** and **next smaller** elements

📌 If *Largest Rectangle in Histogram* is unclear, this problem will feel impossible.

---

## ❓ Why This Problem Is HARD

- 2D matrix problem
- Needs transformation into **1D histogram problem**
- Requires **monotonic stack**
- Multiple layers of logic combined

This problem tests:
- Pattern recognition
- Stack mastery
- Breaking complex problems into simpler ones

---

## ❌ Brute Force Approach (Impossible)

### 🔹 Idea
- Try all possible rectangles
- Check if all elements inside are `'1'`

### ❌ Why This Fails
- Too many rectangles
- Time complexity ~ `O(n³)` or worse
- Will TLE

📌 **Rejected immediately**

---

## 🧠 Key Insight (Turning Point)

Instead of thinking in **2D**, think row by row.

👉 Treat **each row as the base of a histogram**.

---

## 🔁 Matrix → Histogram Transformation

We build an array `heights[]`:

- `heights[j]` = number of **continuous `'1'`s above (including current row)** at column `j`

### Rule:
- If `matrix[i][j] == '1'` → `heights[j]++`
- Else → `heights[j] = 0`

So for **each row**, we get a **histogram**.

---

## 🧠 Subproblem: Largest Rectangle in Histogram

Given `heights[]`, find the **maximum rectangle area**.

### Key idea:
- For each bar, find:
  - Nearest smaller bar on the left
  - Nearest smaller bar on the right
- Width = `right - left - 1`
- Area = `height × width`

This is solved efficiently using a **monotonic increasing stack**.

---

## 🧠 Monotonic Stack Logic (Core)

- Stack stores **indices**
- Heights are in **increasing order**
- When a smaller height is found:
  - Pop from stack
  - Calculate area with popped bar as minimum height

---

## 🧾 Pseudocode – Histogram Part
```cpp
stack = empty
maxArea = 0

for i from 0 to n:
while stack not empty AND currentHeight < height[stack.top]:
h = height[stack.pop()]
width = i if stack empty else i - stack.top - 1
maxArea = max(maxArea, h * width)
push i into stack
```

(Add an extra `0` at the end to flush the stack)

---

## 🧠 Final Optimal Approach (FULL LOGIC)

1. Initialize `heights[]` with zeros
2. For each row:
   - Update `heights[]`
   - Compute **largest rectangle in histogram**
   - Update global maximum area

---

## 🧾 Final Pseudocode (Complete)
```cpp
if matrix empty:
return 0

initialize heights array with 0
maxRectangle = 0

for each row in matrix:
for each column j:
if matrix[row][j] == '1':
heights[j] += 1
else:
heights[j] = 0

maxRectangle = max(
    maxRectangle,
    largestRectangleInHistogram(heights)
)

return maxRectangle
```

---

## 🧪 Dry Run Example

### Input Matrix
```cpp
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```


### Heights after Row 3
```cpp
[3, 1, 3, 2, 2]
```

Largest rectangle in this histogram:
- Height = 2
- Width = 3
- Area = 6 ✅

---

## ⚠️ Edge Cases

- Matrix with all `0`s
- Matrix with single row
- Matrix with single column
- Matrix with all `1`s

---

## 🕒 Time & Space Complexity

- **Time Complexity:**  
  `O(rows × cols)`
- **Space Complexity:**  
  `O(cols)` (stack + heights array)

Optimal and interview-ready.

---

## 🧠 What This Problem Teaches

- Converting 2D → 1D problems
- Power of monotonic stacks
- Recognizing classic subproblems
- Handling HARD problems systematically

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal histogram + stack solution is ACTIVE**
- 📝 **Brute force ideas explained, not used**
- 💬 Code is **human-readable & interview-friendly**
- 🎯 Same clean standard as previous HARD days

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)


