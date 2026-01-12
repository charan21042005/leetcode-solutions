# Day 12 – Minimum Time Visiting All Points  
🟢 **Difficulty:** Easy

🔗 **Problem Link:**  
https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12

---

## 📌 Problem Statement (Simplified)

You are given a list of points on a **2D plane**.

Each point is represented as:
```cpp
(x, y)
```

You start at the **first point** and must visit **all points in order**.

### Movement Rules
In **1 second**, you can move:
- 1 unit **up**
- 1 unit **down**
- 1 unit **left**
- 1 unit **right**
- 1 unit **diagonally**

Your task is to compute the **minimum time** required to visit all points.

---

## 🧠 Prerequisites (Very Basic)

Before solving this problem, you should know:

### 🔹 Coordinate Geometry Basics
- Points on a 2D grid
- Difference between x-coordinates and y-coordinates

### 🔹 Absolute Value
- `|a - b|` represents distance in one direction

### 🔹 Greedy Thinking
- Make the **best local move** at each step
- Diagonal moves save time when possible

---

## ❓ Why This Problem Is Easy

- Direct formula-based solution
- No complex data structures
- No DP or recursion
- Pure observation + greedy logic

This problem mainly tests **logical thinking**.

---

## 🧠 Key Insight (Core Idea)

When moving from point:
```cpp
(x1, y1) → (x2, y2)
```

We want to minimize the number of moves.

---

## 🔍 Understanding Movement Optimally

- Moving **diagonally** changes both `x` and `y` by 1
- So we should use diagonal moves **as much as possible**

---

## 🧮 Mathematical Observation

The minimum time needed to move between two points is:
```cpp
max(|x2 - x1|, |y2 - y1|)
```

### Why?
- Use diagonal moves for the smaller distance
- Use straight moves for the remaining distance

---

## 🧠 Greedy Strategy

For every **consecutive pair of points**:
1. Compute `dx = |x2 - x1|`
2. Compute `dy = |y2 - y1|`
3. Time needed = `max(dx, dy)`
4. Add to total time

---

## 🧾 Pseudocode
```cpp
time = 0

for i from 1 to n-1:
dx = abs(points[i][0] - points[i-1][0])
dy = abs(points[i][1] - points[i-1][1])
time += max(dx, dy)

return time
```

---

## 🧪 Dry Run Example

### Input
```cpp
points = [[1,1], [3,4], [-1,0]]
```

### Step 1
```cpp
From (1,1) → (3,4)

dx = 2, dy = 3
time = max(2,3) = 3
```


### Step 2
```cpp
From (3,4) → (-1,0)

dx = 4, dy = 4
time = max(4,4) = 4
```


### Total Time
```cpp
3 + 4 = 7
```

---

## ⚠️ Edge Cases

- Only one point → time = 0
- Points in straight line
- Points already adjacent

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

Very efficient.

---

## 🧠 What This Problem Teaches

- How diagonal movement reduces time
- Greedy thinking
- Converting movement into a math formula
- Writing clean and efficient code

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal greedy solution**
- 💬 Code is **simple, clean, and readable**
- 🎯 Maintains same professional repo standard

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)



