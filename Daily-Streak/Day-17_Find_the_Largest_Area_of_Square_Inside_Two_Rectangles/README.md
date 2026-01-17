# Day 17 – Find the Largest Area of Square Inside Two Rectangles  
🟡 **Difficulty:** Medium  

🔗 **Problem Link:**  
https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/

---

## 📌 Problem Statement (Simplified)

You are given **n axis-aligned rectangles** on a 2D plane.

Each rectangle is defined by:
- `bottomLeft[i] = (x1, y1)`
- `topRight[i]   = (x2, y2)`

Your task is to:

👉 Find the **maximum possible area of a square** that can fit  
**inside the intersection region of at least two rectangles**.

If **no two rectangles intersect**, return `0`.

---

## 📌 Problem Summary

- Rectangles are parallel to x and y axes
- You must choose **any pair of rectangles**
- Consider **only their intersection region**
- Inside that intersection, fit the **largest possible square**
- Return the **maximum square area** among all rectangle pairs

---

## 🧠 Prerequisites (Must Know Before Solving)

### 🔹 Programming Basics
- Nested loops
- Min / Max operations
- Conditional checks

### 🔹 Mathematical Concepts
- Rectangle intersection
- Length & width calculation
- Square properties
- Area = side × side

### 🔹 DSA Concepts
- Brute force pair checking
- Geometry → math reduction
- Greedy maximization

---

## ❓ Why This Problem Is Medium

At first glance, it looks like:
- Geometry heavy
- 2D spatial reasoning
- Possibly needs advanced data structures

But in reality:

✅ Constraints are small  
✅ Simple math works  
✅ Brute force is acceptable  

This problem tests:
- Rectangle intersection understanding
- Careful boundary handling
- Turning geometry into numbers

---

## 🧠 Key Observation (Most Important)

A **square inside a rectangle** is limited by:
```cpp
side ≤ min(width, height)
```
So for **two rectangles**:

1. First find their **intersection rectangle**

2. Then compute:
```cpp
side = min(intersectionWidth, intersectionHeight)
area = side × side
```

## 🧱 Rectangle Intersection Basics

For two rectangles A and B:

### **Intersection boundaries**:
```cpp
left   = max(A.x1, B.x1)
right  = min(A.x2, B.x2)

bottom = max(A.y1, B.y1)
top    = min(A.y2, B.y2)
```

### Intersection dimensions:
```cpp
width  = right - left
height = top - bottom
```

### ⚠️ Valid intersection only if:
```cpp
width > 0 AND height > 0
```

## ❌ Approach 1: Advanced Geometry / Sweep Line (Overkill)
### ❌ **Why Not Needed**

* n ≤ 1000
* Pairwise checks are fine
* Sweep line adds complexity without benefit

**📌 Rejected – unnecessary overengineering**


## ✅ Optimal Approach (USED) – Brute Force + Math
🔹 Strategy
1. Try **all pairs of rectangles** `(i, j)`
2. Compute their intersection
3. If intersection exists:
    * Compute max square side
    * Compute area

4. Track **maximum area**

## 🧠 Why Brute Force Works Here
* Total pairs = `n(n-1)/2`
* n ≤ 1000 → ~500k pairs
* Each operation is O(1)

✔ Safe
✔ Fast
✔ Clean


## 🧮 Step-by-Step Algorithm
1️⃣ Iterate Over All Pairs
```cpp
for i in range(n):
    for j in range(i+1, n):
```
2️⃣ Compute Intersection Rectangle
```cpp
left   = max(x1[i], x1[j])
right  = min(x2[i], x2[j])
bottom = max(y1[i], y1[j])
top    = min(y2[i], y2[j])
```
3️⃣ Validate Intersection
```cpp
width  = right - left
height = top - bottom

if width <= 0 or height <= 0:
    continue
```
4️⃣ Compute Square Area
```cpp
side = min(width, height)
area = side * side
```
5️⃣ Track Maximum
```cpp
ans = max(ans, area)
```

## 🧪 Example Walkthrough
Example 1
```cpp
Rect A: (1,1) → (3,3)
Rect B: (2,2) → (4,4)
```
Intersection:
```cpp
(2,2) → (3,3)
width = 1
height = 1
side = 1
area = 1
```

Example 2
```cpp
Rect A: (1,1) → (5,5)
Rect B: (1,3) → (5,7)
```
Intersection:
```cpp
(1,3) → (5,5)
width = 4
height = 2
side = 2
area = 4
```

## 🧾 Pseudocode (Optimal)

```cpp
ans = 0
n = number of rectangles

for i = 0 to n-1:
    for j = i+1 to n-1:

        left   = max(bottomLeft[i].x, bottomLeft[j].x)
        right  = min(topRight[i].x,  topRight[j].x)
        bottom = max(bottomLeft[i].y, bottomLeft[j].y)
        top    = min(topRight[i].y,  topRight[j].y)

        width  = right - left
        height = top - bottom

        if width <= 0 or height <= 0:
            continue

        side = min(width, height)
        ans = max(ans, side * side)

return ans
```

## ⚠️ Edge Cases to Consider
* No intersecting rectangles → return `0`
* Itersection is a line or point → ignore
* Multiple rectangles intersecting → any pair allowed
* Large coordinates (use `long long`)

## ⏱️ Complexity Analysis

Time Complexity:
```cpp
O(n²)
```

Space Complexity:
```cpp
O(1)
```

✔ Efficient for given constraints
✔ No risk of TLE


## 🧠 What This Problem Teaches
* Geometry problems can often be simplified to math
* Rectangle intersection is a **core interview skill**
* Don’t overthink when constraints allow brute force
* Squares are controlled by their **smallest dimension**

## 📂 Files in This Folder

* 📄 Solution.cpp
* 📄 Solution.java
* 📄 Solution.py

Each file contains:

* ✅ Optimal brute-force + math solution
* 💬 Beginner-friendly comments
* 🧪 Clean & readable logic