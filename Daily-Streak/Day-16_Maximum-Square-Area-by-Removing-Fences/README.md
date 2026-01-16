# Day 16 – Maximum Square Area by Removing Fences From a Field  
🟡 **Difficulty:** Medium  

🔗 **Problem Link:**  
https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/

---

## 📌 Problem Statement (Simplified)

You are given a rectangular field with corners at `(1, 1)` and `(m, n)`.

Inside the field:
- Some **horizontal fences** exist (`hFences`)
- Some **vertical fences** exist (`vFences`)

You are allowed to **remove any number of internal fences**  
⚠️ The **boundary fences cannot be removed**.

Your task is to form a **perfect square-shaped field** and return the  
👉 **maximum possible square area**.

If it is **impossible**, return `-1`.

Since the answer can be large, return it **modulo `10^9 + 7`**.

---


## 📌 Problem Summary

You are given a large rectangular field with corners at:
```cpp
(1, 1) and (m, n)
```

Inside the field:
- Some **horizontal fences** exist at given y-coordinates (`hFences`)
- Some **vertical fences** exist at given x-coordinates (`vFences`)

⚠️ The **outer boundary fences cannot be removed**.

You may remove **any number of internal fences**.

### 🎯 Goal

Form a **perfect square-shaped field** by removing fences and  
return the **maximum possible square area**.

If it is **impossible to form a square**, return `-1`.

Since the result can be large, return it **modulo `10^9 + 7`**.

---

## 🧠 Prerequisites (Must Know Before Solving)

Before solving this problem, you should be comfortable with:

### 🔹 Programming Basics
- Arrays / lists
- Sorting
- Looping through arrays
- Tracking maximum values

### 🔹 Mathematical Concepts
- Distance between two points
- Squares and areas
- Minimum / maximum logic
- Modulo arithmetic

### 🔹 DSA Concepts
- Greedy algorithms
- Observation-based optimization
- Reducing 2D problems into 1D

---

## ❓ Why This Problem Is Medium

At first glance, this looks like a **2D geometry problem**.

But the real challenge is:
- Realizing you **don’t need geometry formulas**
- Identifying that **removing fences merges intervals**
- Reducing the problem to **simple distance calculations**

This problem tests:
- Problem reduction
- Greedy reasoning
- Boundary handling

---

## 🧠 Key Observation (Most Important)

> A square is completely determined by its **side length**.

So instead of thinking in **2D**, we reduce the problem into **two independent 1D problems**:
- Maximum vertical distance (height)
- Maximum horizontal distance (width)

Then:
```cpp
square side = min(maxHeight, maxWidth)

square area = side × side
```

---
## ❌ Approach 1: Brute Force (Not Practical)

### 🔹 Idea
- Try removing different combinations of fences
- Check all possible rectangles
- Verify if any is a square
- Track maximum area

### ❌ Why This Fails
- Fence combinations grow exponentially
- Checking all rectangles is inefficient
- Completely unnecessary for given constraints

📌 **Rejected due to excessive complexity**

---
## 🧠 Key Observation (Turning Point)

A square is defined by **one value only**:

> ✅ Its **side length**

So instead of thinking in 2D:
- Compute **maximum vertical length**
- Compute **maximum horizontal length**

Then:
```text
squareSide = min(maxVerticalGap, maxHorizontalGap)
```
---

## 🔑 Core Insight (Very Important)

Removing fences **merges adjacent segments**.

So the problem becomes:

> **Find the maximum distance between two remaining fences**

Do this:
* Once for horizontal direction
* Once for vertical direction

The square side is limited by the **smaller** of the two.

---

## ✅ Optimal Greedy Approach (USED)
🔹 Strategy
1. Add **boundary fences**:
    * Horizontal → `1` and `m`
    * Vertical → `1` and `n`
2. Sort fence positions
3. Compute **maximum consecutive gap**
4. Square side = **min(maxHeight, maxWidth)**
5. Return **side × side** (modulo)


---


## 🔁 Geometry → 1D Reduction

### Vertical Direction (Height)

- Horizontal fences split the field into vertical strips
- Removing fences merges strips
- We want the **maximum continuous vertical gap**

### Horizontal Direction (Width)

- Vertical fences split the field into horizontal strips
- Removing fences merges strips
- We want the **maximum continuous horizontal gap**

👉 The problem becomes:
> **Find the maximum distance between two remaining fences**

---

## 🧱 Understanding Fences Clearly

Even if `hFences` is empty, the field still has:
- Fence at `y = 1`
- Fence at `y = m`

Similarly for vertical:
- Fence at `x = 1`
- Fence at `x = n`

These **must be included** in calculations.

---

## 🧠 Greedy Insight

To get the **largest square**:
- We want the **largest vertical gap**
- And the **largest horizontal gap**

This can be done by:
1. Sorting fence positions
2. Computing consecutive differences
3. Taking the maximum gap

This greedy choice is **always optimal**.

---

## 🧮 Step-by-Step Strategy

### 1️⃣ Add Boundary Fences

For horizontal:
```text
1, hFences..., m

For vertical:
1, vFences..., n
```

### 2️⃣ Sort Fence Positions

Sorting allows us to easily compute gaps between adjacent fences.

### 3️⃣ Compute Maximum Gap

For a sorted list `fences`:
```cpp
maxGap = max(fences[i] - fences[i-1])
```
Do this separately for:

* Horizontal fences → `maxHeight`

* Vertical fences → `maxWidth`

### 4️⃣ Determine Square Possibility
```cpp
side = min(maxHeight, maxWidth)
```

* If `side == 0` → no square possible → return `-1`

* Else return `(side * side) % MOD`

## 🧪 Example Walkthrough
Example
```cpp
m = 4, n = 3
hFences = [2, 3]
vFences = [2]
```

Horizontal fences:
```cpp
[1, 2, 3, 4]
Gaps → 1, 1, 1
maxHeight = 1
```

Vertical fences:
```cpp
[1, 2, 3]
Gaps → 1, 1
maxWidth = 1
```
```cpp
Square side = 1
Area = 1 × 1 = 1
```
---

## 🧾 Pseudocode (Optimal)
```cpp
add 1 and m to hFences
add 1 and n to vFences

sort hFences
sort vFences

maxHeight = max(hFences[i] - hFences[i-1])
maxWidth  = max(vFences[i] - vFences[i-1])

side = min(maxHeight, maxWidth)

if side == 0:
    return -1
else:
    return (side * side) % MOD
```

## 🧪 Dry Run Example
Example 1
```cpp
m = 4, n = 3
hFences = [2, 3]
vFences = [2]
```

After adding boundaries:
```cpp
Horizontal: [1, 2, 3, 4]
Gaps → 1, 1, 1 → maxHeight = 1

Vertical: [1, 2, 3]
Gaps → 1, 1 → maxWidth = 1
```
```cpp
Square side = `1`
Area = `1 × 1 = 1`
```
--- 

## ⚠️ Edge Cases to Consider
* No removable fences
* Only one removable fence
* Very large `m` and `n`
* Gaps exist only in one direction
* Result exceeds integer range → use modulo

---

## ❌ When Is Square Impossible?

If **either direction** has:
```cpp
max gap = 0
```

Then:
* You cannot form a square
* Return `-1`

---

## ⚠️ Why No Advanced Data Structures?
* Fence count ≤ 600
* Sorting is enough
* No need for DP, segment tree, or geometry sweeps

This is a **pure greedy + math** problem.

---

## ⏱️ Complexity Analysis

Sorting fences: O(k log k)

Single scan for gaps: O(k)

Where:
```cpp
k ≤ 600
```

✔ Extremely fast

✔ No risk of TLE

## 🧠 What This Problem Teaches

* Reduce 2D geometry into **independent 1D problems**
* Always include **boundary conditions**
* Greedy works when choices are **locally optimal & independent**
* Avoid overengineering simple constraints

## 📂 Files in This Folder

* 📄 Solution.cpp
* 📄 Solution.java
* 📄 Solution.py

Each file contains:
* ✅ Optimal greedy solution
* 💬 Beginner-friendly comments
* 🧪 Standalone logic (easy to test)