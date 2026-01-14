# Day 14 – Separate Squares II  
🔴 **Difficulty:** Hard

🔗 **Problem Link:**  
https://leetcode.com/problems/separate-squares-ii/description/?envType=daily-question&envId=2026-01-14

---

## 📌 Problem Statement (Simplified)

You are given **n axis-aligned squares** on a 2D plane.

Each square is represented as:
```cpp
[x, y, side]
```
Where:
- `(x, y)` is the **bottom-left corner**
- `side` is the **side length**

Your task is to find a **horizontal line y = k** such that:
- The **total area strictly above the line**
  equals
- The **total area strictly below the line**

Return the value of `k`.

If multiple answers exist, return **any**.

---

## 🔁 What Changed from Separate Squares I → II (VERY IMPORTANT)

### ✅ Part I (Day-13)
- Squares were **simple enough**
- A sweep-line over y **with total width only** was sufficient
- Overlaps were handled, but **no x-structure mattered**
- Precision tolerance was forgiving

---

### ❌ Why That Is NOT Enough for Part II

In **Separate Squares II**:

1️⃣ **Squares can overlap arbitrarily in both X and Y**  
2️⃣ Horizontal slices may have **multiple disjoint x-intervals**  
3️⃣ You cannot treat a square as contributing a single “width”  
4️⃣ Precision requirements are **much stricter**  
5️⃣ Area density changes **continuously**, not step-wise  

👉 This means:
> **We must compute the exact union width at every y-interval.**

---

## 🧠 Prerequisites (Must Know)

Before attempting this problem, you must understand:

### 🔹 Geometry
- Area as integral of width over height
- Union of intervals on a line

### 🔹 Sweep Line Algorithm
- Event-based scanning
- Maintaining active intervals
- Prefix / differential counting

### 🔹 Precision Handling
- Floating point stability
- Binary search on real numbers
- Error tolerance (`1e-6`)

This is **advanced geometry**, not a basic math problem.

---

## ❓ Why This Problem Is HARD

- Area is **continuous**, not discrete
- Overlaps in **both x and y**
- Requires **nested sweeps** (y-sweep + x-interval merge)
- Needs **binary search on answer**
- Must avoid floating-point drift

This is **FAANG-level geometry**.

---

## ❌ Incorrect Assumption from Part I (Common Pitfall)

> “At a given y, total width = sum of sides of active squares.”

❌ **WRONG in Part II**

Why?
- Two squares may overlap in x
- Overlapping x-intervals must be merged
- Width = **union length**, not sum

---

## 🧠 Key Insight (Core Idea)

Instead of finding `k` directly, we **binary search on y**.

For any candidate height `mid`:
- Compute area **below mid**
- Compare with `total_area / 2`

This converts the problem into a **decision problem**:
```cpp
Is area_below(mid) >= total_area / 2 ?
```

---

## 🧠 Area Computation at a Given y

For a fixed y = mid:

### For each square:
- If square is fully above → contributes 0
- If square is fully below → contributes full area
- If square is cut:
  - Effective height = `mid - bottom`
  - Contributes partial rectangle

But crucially:
👉 The **width** at that slice is the **union of x-intervals**.

---

## 🧠 How to Compute Union Width

1️⃣ Collect all active x-intervals  
2️⃣ Sort by starting x  
3️⃣ Merge overlapping intervals  
4️⃣ Sum merged lengths  

This gives **exact horizontal coverage** at that height.

---

## 🧠 Overall Strategy (Optimal)

### Step 1️⃣: Compute Total Area
```cpp
total_area = sum(side² for all squares)
```

---

### Step 2️⃣: Binary Search on y

Search range:
```cpp
low = min(bottom y)
high = max(top y)
```

For each mid:
- Compute area below mid using:
  - Partial square heights
  - Union of x-intervals
- Compare with `total_area / 2`

---

### Step 3️⃣: Precision Control

Binary search until:
```cpp
high - low < 1e-6

Return mid.
```

---

## 🧾 Pseudocode (High-Level)
```cpp
compute total_area
target = total_area / 2

low = min_y
high = max_y

while high - low > epsilon:
mid = (low + high) / 2
area = compute_area_below(mid)

if area < target:
    low = mid
else:
    high = mid

return low
```


---

## 🧪 Why Binary Search Is Required

- Area increases **monotonically** as y increases
- Direct formula does not exist
- Binary search guarantees convergence

---

## ⚠️ Precision Pitfalls (VERY IMPORTANT)

- Use `double` / `float64`
- Avoid equality comparisons
- Stop with tolerance, not exact match
- Return any valid answer within error bounds

---

## 🕒 Time & Space Complexity

Let `n` = number of squares

- **Time Complexity:**  
  `O(log(range) × n log n)`
- **Space Complexity:**  
  `O(n)`

This is optimal for this problem.

---

## 🧠 What This Problem Teaches

- Difference between **object area** and **union area**
- Nested sweep-line thinking
- Binary search on continuous domain
- Precision-safe coding
- Advanced computational geometry

---

## ✅ Code Strategy Used in This Repo

- ✅ **Binary search + sweep-line union width**
- 📝 **Incorrect Part I assumptions explained**
- 💬 Code written clearly & defensively
- 🎯 Interview-ready documentation

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

