# Day 14 – Separate Squares II  
🔴 **Difficulty:** Hard  

🧠 **Note:** This is considered one of the *toughest geometry problems on LeetCode*.  
It requires combining **sweep line**, **segment tree**, and **union-area computation**,  
where even small mistakes in event ordering or initialization can lead to **Wrong Answer or TLE**.

🔗 **Problem Link:**  
https://leetcode.com/problems/separate-squares-ii/description/?envType=daily-question&envId=2026-01-14

---

## 📌 Problem Summary

You are given **n axis-aligned squares** on a 2D plane.  
Each square is defined as:
```cpp
[x, y, side]
```

- `(x, y)` → bottom-left corner  
- `side` → side length  

Your task is to find a **horizontal line `y = k`** such that:

> **Total area strictly below the line**  
> equals  
> **Total area strictly above the line**

Return the value of `k`.  
If multiple answers exist, return **any valid one**.

---

## 🔁 How This Differs from Separate Squares I

| Separate Squares I | Separate Squares II |
|-------------------|---------------------|
| Overlaps mostly manageable | Arbitrary overlaps in **X and Y** |
| Simple sweep sometimes works | Simple sweep **fails / TLE** |
| Area accumulation easier | Must compute **union area** |
| No heavy DS required | **Segment Tree REQUIRED** |

👉 **This problem is significantly harder.**

---

## 🌳 Segment Tree Basics (From Level 0)

This problem cannot be solved without understanding **what a Segment Tree does**  
and **why it is required here**.

This section explains Segment Trees from **absolute basics**.

---

## ❓ What Problem Is the Segment Tree Solving Here?

At any height `y`, we must compute:

> **Total horizontal length covered by active squares**

Each active square contributes an interval on the X-axis:

```cpp
[x_left, x_right]
```

Many such intervals may:
- Overlap
- Touch
- Be disjoint

👉 We need the **UNION LENGTH** of these intervals.

---

## ❌ Why Simple Methods Fail

### ❌ Just summing widths
```cpp
width = (x2-x1) + (x4-x3)
```
Fails when intervals overlap → double counting.

### ❌ Sorting & merging every time
- Works logically
- But repeated for many Y-values
- Leads to **Time Limit Exceeded**

---

## ✅ Why Segment Tree Is the Right Tool

A Segment Tree allows us to:
- Add an interval `[x1, x2)` → **O(log n)**
- Remove an interval `[x1, x2)` → **O(log n)**
- Query total union length → **O(1)**

This is exactly what we need during the Y-sweep.

---

## 🧠 Core Idea of Segment Tree (Very Simple)

Think of the X-axis as divided into **small segments**:

```cpp
|----|----|----|----|
x0 x1 x2 x3 x4
```

Each segment:
- Represents a small interval `[xi, xi+1)`
- Can be covered by 0 or more squares

The Segment Tree keeps track of:
1. **How many squares cover this segment**
2. **How much length is covered in total**

---

## 🧩 Coordinate Compression (IMPORTANT)

We cannot build a tree on raw X-values like:
```cpp
x = 1e9
```

So we:
1. Collect all `x` and `x + side`
2. Sort them
3. Map them to indices

Example:
```cpp
Original X values: [1, 5, 10]
Compressed indices: 0, 1, 2
```

Now the tree works on indices, but stores **real lengths**.

---

## 🌳 Segment Tree Node Meaning

Each node represents a range:
```cpp
[x_left, x_right)
```

And stores two values:

### 1️⃣ coveredCount
How many active intervals fully cover this node

### 2️⃣ coveredWidth
Total union width contributed by this node


---

## 🧠 Push-Up Rule (MOST IMPORTANT LOGIC)

When updating the tree:
```cpp
If coveredCount > 0:
coveredWidth = xs[right+1] - xs[left]
Else if leaf:
coveredWidth = 0
Else:
coveredWidth = leftChild.coveredWidth + rightChild.coveredWidth
```

📌 This rule guarantees:
- No double counting
- Correct union length

---

## 🧪 Simple Example

Active intervals:
```cpp
[1, 5], [3, 7]
```

Merged union:
```cpp
[1, 7]
```

Segment Tree automatically computes:
```cpp
coveredWidth = 6
```

---

## 🔁 How Segment Tree Is Used in This Problem

During Y-sweep:

1. When a square **starts**:
```cpp
add(x_left, x_right, +1)
```

2. When a square **ends**:
```cpp
add(x_left, x_right, -1)
```

3. At any moment:
```cpp
tree.getCoveredWidth()
```
returns current union width on X-axis.

---

## 🔗 Connection to Area Calculation

For two consecutive Y-events:
```cpp
area += unionWidth × deltaY
```

This is how **2D area** is built from **1D union width**.

---

## ⚠️ Key Takeaway

> Segment Tree is NOT optional here.  
> It is the **only data structure** that gives:
>
> - Correctness
> - Speed
> - Precision

Without it:
- Logic may be correct
- But solution will **TLE**

---

## 🎯 Why This Matters for Interviews

This problem tests:
- Sweep line technique
- Segment Tree fundamentals
- Union of intervals
- Real-world geometry modeling

Understanding this means you truly understand **advanced DSA**, not just syntax.



## 🧠 Key Insight (Most Important)

> **Area is NOT computed per square.  
> Area is computed per horizontal strip using the UNION of X-intervals.**

At any height `y`:
1. Multiple squares may be active
2. Their projections on the X-axis may overlap
3. Width = **union length**, not sum

---

## ❌ Why Naive Approaches Fail

### ❌ Binary Search on Y Only
- Cannot compute area fast enough
- Still requires union calculation each time → **TLE**

### ❌ Slab-by-slab recomputation
- Rebuilding X-interval unions repeatedly
- Time complexity → `O(n² log n)` → **TLE**

### ❌ Treating squares independently
- Overlaps cause double counting → **Wrong Answer**

---

## ✅ Correct High-Level Strategy (Editorial Level)

We use a **Sweep Line on Y-axis + Segment Tree on X-axis**.

---

## 🧠 Step-by-Step Strategy

### 1️⃣ Convert Squares into Y-Events

Each square generates two events:
```cpp
(y, +1, x_left, x_right) // square enters
(y + side, -1, x_left, x_right) // square leaves
```

Between two Y-events:
- The set of active squares does NOT change.

---

### 2️⃣ Coordinate Compression on X

Segment Trees work on indices, not raw values.

So we:
- Collect all `x` and `x + side`
- Sort & compress them
- Build the tree on compressed X segments

---

### 3️⃣ Segment Tree Responsibilities

The segment tree maintains:
- `coveredCount[node]` → how many intervals cover this segment
- `coveredWidth[node]` → union width of this segment

**Core logic:**
```cpp
If coveredCount > 0:
    coveredWidth = xs[right+1] - xs[left]
Else if leaf:
    coveredWidth = 0
Else:
    coveredWidth = leftChild.coveredWidth + rightChild.coveredWidth

```

This guarantees **correct union width**.

---

### 4️⃣ Sweep Line on Y (Area Accumulation)

We sweep events in increasing Y order.

Between two Y-values:
```cpp
area += unionWidth × (currentY - previousY)
```

We keep accumulating area until it reaches `totalArea / 2`.

---

### 5️⃣ Compute Exact Answer

When area crosses half:
```cpp
k = prevY + (remainingArea / unionWidth)
```

This gives an **exact floating-point answer**.

---

## 🧾 Pseudocode (High-Level)
```cpp
Create Y-events from squares
Compress X-coordinates
Build segment tree on X

totalArea = 0
Compute total union area by sweeping once

target = totalArea / 2
currentArea = 0

Sweep Y-events again:
deltaY = y - prevY
areaGain = unionWidth * deltaY

if currentArea + areaGain >= target:
    return exact y inside strip

currentArea += areaGain
apply event updates to segment tree
```

---

## ⚠️ Precision Notes

- Use `double`
- Avoid equality checks
- Continuous geometry → approximation acceptable
- Segment tree ensures numeric stability

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

This is **optimal and required** to pass.

---

## 🧠 What This Problem Teaches

- Difference between **area sum** and **union area**
- Why advanced geometry needs data structures
- Practical use of **Segment Trees**
- Sweep-line techniques in real problems

---

## 📂 Files in This Folder

- 📄 `Solution.cpp` → **Optimal & Accepted**
- 📄 `Solution.java` → (Reference / Educational)
- 📄 `Solution.py` → (Reference / Educational)

> ⚠️ Note: Due to constraints, **C++ is the recommended language** for this problem.

---

## ✅ Final Status

✔ Correct approach  
✔ Handles all overlaps  
✔ No TLE  
✔ Editorial-grade  
✔ Industry-level documentation  

---

🔥 **This is one of the hardest geometry problems on LeetCode.  
Finishing it properly is a BIG achievement.**



