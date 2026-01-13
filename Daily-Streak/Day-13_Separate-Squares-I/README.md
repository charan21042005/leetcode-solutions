# Day 13 – Separate Squares I  
🟡 **Difficulty:** Medium

🔗 **Problem Link:**  
https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13

---

## 📌 Problem Statement (Simplified)

You are given **n axis-aligned squares** on a 2D plane.

Each square is defined by:
```cpp
[x, y, side]
```
Where:
- `(x, y)` is the **bottom-left corner**
- `side` is the **side length** of the square

Your task is to find a **horizontal line y = k** such that:
- The **total area of squares strictly above the line**  
  equals  
- The **total area of squares strictly below the line**

Return the value of `k`.

📌 If multiple answers exist, return **any valid one**.

---

## 🧠 Prerequisites (Very Important)

Before solving this problem, you should understand:

### 🔹 Coordinate Geometry
- Cartesian plane (x-axis, y-axis)
- Horizontal lines (`y = constant`)
- Vertical distances

### 🔹 Area Basics
- Area of a square = `side × side`
- Partial area when a shape is cut by a line

### 🔹 Observation-Based Problem Solving
- Instead of simulating every point, reason mathematically
- Reduce the problem to **prefix/suffix area comparison**

---

## ❓ Why This Problem Is Medium

- Involves **continuous values**, not integers
- Requires **partial area computation**
- Needs careful handling of overlapping squares
- Demands a **global balance condition**

This problem tests:
- Geometric reasoning
- Mathematical observation
- Precision handling

---

## ❌ Brute Force Approach (Not Feasible)

### 🔹 Idea
- Try every possible y-value
- Compute area above and below

### ❌ Why This Fails
- Infinite possible y-values (real numbers)
- Too slow and impractical

📌 We need a **smart mathematical approach**.

---

## 🧠 Key Insight (Turning Point)

Think of **sweeping a horizontal line from bottom to top**.

As the line moves:
- Area **below** the line increases
- Area **above** the line decreases

👉 At some point, they become equal.

This is a **balance point** problem.

---

## 🧠 How Squares Contribute to Area

For a square with:
```cpp
bottom = y
top = y + side
area = side²
```

For a horizontal line at `k`:

### Case 1️⃣: Square completely below the line
```cpp
top ≤ k
→ Entire area contributes to BELOW
```


### Case 2️⃣: Square completely above the line
```cpp
bottom ≥ k
→ Entire area contributes to ABOVE
```


### Case 3️⃣: Line cuts through the square
```cpp
bottom < k < top

- Area below:
(k - bottom) × side

- Area above:
(top - k) × side
```

---

## 🧠 Reformulating the Problem

We want:
```cpp
Area_below(k) = Area_above(k)
```

Which is equivalent to:
```cpp
Area_below(k) = Total_area / 2
```

📌 This simplifies the problem greatly.

---

## 🧠 Correct Strategy (Sweep Line with Area Density)

Instead of adding square areas one by one, we must account for the fact that
**squares can overlap vertically**.

So we use a **sweep-line approach on the y-axis**:

1. For each square:
   - Add an event at `y = bottom` with `+side`
   - Add an event at `y = bottom + side` with `-side`
2. Sort all events by y-coordinate
3. Sweep from bottom to top while maintaining:
   - `current_width` = total horizontal coverage at that height
4. For each consecutive y-interval:
   - Area added = `(y_next - y_current) × current_width`
5. Stop when accumulated area reaches `total_area / 2`
6. Compute the exact cut position using proportional height


## ⚠️ Common Mistake (Important)

A common incorrect approach is to:
- Sort squares by bottom y-coordinate
- Add full square areas sequentially

❌ This fails when squares **overlap in the y-direction**.

✔ The correct solution must treat area accumulation as **continuous over y**,
which is why a **sweep-line with events** is required.


---

## 🧾 Pseudocode (High-Level)
```cpp
total_area = sum(side² for each square)
target = total_area / 2
current_area = 0

sort squares by bottom y

for each square:
if current_area + square.area < target:
current_area += square.area
else:
remaining = target - current_area
k = square.bottom + remaining / square.side
return k
```

---

## 🧪 Dry Run Example

### Input
```cpp
squares = [[0,0,2], [0,2,2]]
```

### Areas
- Square 1 area = 4
- Square 2 area = 4
- Total area = 8
- Target = 4

### Sweep
- First square contributes 4 → reaches target exactly
- Separation line:
```cpp
k = 2
```

---

## ⚠️ Edge Cases to Handle

- Multiple squares overlapping in y-direction
- Line passing exactly at square boundary
- Large coordinate values
- Floating point precision

---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n log n)`
  - Sorting dominates
- **Space Complexity:** `O(1)` extra space

Efficient and clean.

---

## 🧠 What This Problem Teaches

- Turning geometry into prefix sums
- Handling partial areas mathematically
- Continuous values in algorithmic problems
- Sweep-line style thinking

---

## ✅ Code Strategy Used in This Repo

- ✅ **Optimal sweep-line + math approach**
- 📝 **Brute force ideas explained, not used**
- 💬 Code written in **human-friendly style**
- 🎯 Same professional documentation standard

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

