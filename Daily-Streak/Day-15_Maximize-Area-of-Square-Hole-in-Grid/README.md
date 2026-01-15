# Day 15 – Maximize Area of Square Hole in Grid  
🟡 **Difficulty:** Medium  

🔗 **Problem Link:**  
https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/

---

## 📌 Problem Summary

You are given a grid formed by **horizontal and vertical bars**.

- The grid has:
  - `n + 2` horizontal bars
  - `m + 2` vertical bars
- These bars create **1 × 1 unit cells**

Some bars are **removable**:
- `hBars` → removable horizontal bars
- `vBars` → removable vertical bars

All other bars are **fixed** and cannot be removed.

---

## 🎯 Objective

After removing **any number of allowed bars**, you must find:

> The **maximum possible area of a square-shaped hole** in the grid.

Return **the area** of that square.

---

## 🧠 Key Observation (Most Important)

A **square hole** means:

- The width (horizontal gap)  
- and the height (vertical gap)  

must be **equal**.

So the problem reduces to:

> Find the **largest continuous gap** between horizontal bars  
> and the **largest continuous gap** between vertical bars  
> then take the **minimum** of those two gaps.

---

## 🧩 Understanding the Grid (From Basics)

Bars are indexed starting from `1`.

Example:
```cpp
Horizontal bars: 1 2 3 4
Vertical bars: 1 2 3
```

If you remove **bar 2**, bars `1` and `3` connect → forming a larger gap.

So:
- Removing **consecutive bars** creates **bigger holes**
- Removing scattered bars does **not** help much

---

## ❓ What Actually Creates a Square Hole?

A square hole of side `k` exists if:
- There are **k consecutive horizontal segments**
- AND **k consecutive vertical segments**

The **area = k × k**

---

## 🧠 Core Insight (Greedy)

### Step 1️⃣  
Sort the removable bars.

### Step 2️⃣  
Find the **longest consecutive sequence** of bars.

Example:
```cpp
hBars = [2, 3, 4]
Longest consecutive = 3 bars → gap size = 4
```


Why `+1`?
- Because bars form boundaries
- 3 removed bars create **4 cells**

---

## 📐 Why We Add 1 to the Length

If bars are at:
```cpp
2, 3, 4
```
Then the gap spans:
```cpp
1 | 2 | 3 | 4 | 5
```
So:
```cpp
gap = consecutive_count + 1
```

---

## 🧮 Final Formula

Let:
- `maxH` = largest horizontal gap
- `maxV` = largest vertical gap

Then:
```cpp
side = min(maxH, maxV)
area = side × side
```

---

## ❌ Common Mistakes

❌ Trying DP or graph traversal  
❌ Treating grid as matrix  
❌ Overthinking geometry  

✅ This is a **sorting + greedy gap problem**

---

## 🧾 Pseudocode (High-Level)
```cpp
sort hBars
sort vBars

maxH = longestConsecutive(hBars) + 1
maxV = longestConsecutive(vBars) + 1

side = min(maxH, maxV)
return side * side
```

## ⏱️ Complexity Analysis

- **Sorting:** `O(k log k)`
- **Single Scan:** `O(k)`

Where:
- `k ≤ 100` (number of removable bars)

✔ Extremely efficient  
✔ No risk of TLE  

---

## 🧠 What This Problem Teaches

- Convert **geometry problems** into **1D reasoning**
- Focus on **gaps**, not individual cells
- Recognize when a **greedy approach** is sufficient
- Avoid unnecessary data structures or overengineering

---

## 📂 Files in This Folder

- 📄 `Solution.cpp`
- 📄 `Solution.java`
- 📄 `Solution.py`

Each file contains:

- ✅ Optimal solution
- 💬 Beginner-friendly comments
- 🧪 Standalone logic (easy to test and understand)

