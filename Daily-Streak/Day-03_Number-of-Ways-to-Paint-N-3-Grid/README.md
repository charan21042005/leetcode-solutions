# Day 03 – Number of Ways to Paint N × 3 Grid  
🔴 Difficulty: HARD

🔗 **Problem Link:**  
https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03

---

## 🧠 Prerequisites (Must Know Before Solving)

Before attempting this problem, you should be comfortable with:

### 🔹 Programming Concepts
- Arrays & loops
- Modulo arithmetic (`10^9 + 7`)
- Writing clean iterative logic

### 🔹 DSA Concepts
- Dynamic Programming (DP)
- State definition in DP
- Transition between states
- Space optimization in DP

### 🔹 Mathematical Thinking
- Counting techniques
- Pattern recognition
- Observing symmetry
- Reducing large problems into smaller repeating units

📌 **If DP state definition is unclear → this problem will feel impossible.**

---

## 📌 Problem Statement (Simplified)

You are given a grid of size **N × 3**.

You must paint each cell using **3 colors**, such that:
- No two **adjacent cells** (up, down, left, right) have the same color.

Return the **number of valid colorings** modulo `10^9 + 7`.

---

## ❓ Why This Problem Is HARD

- Grid height `N` can be very large
- Each row depends on the **previous row**
- Constraints apply **horizontally AND vertically**
- Direct counting is infeasible
- Requires **DP + pattern compression**

This problem tests:
> 🧠 *Your ability to reduce a complex grid problem into a small number of states.*

---

## ❌ Approach 0: Brute Force (Why It Fails)

### 🔹 Idea
Try all possible colorings.

### 🔹 Why it fails
- Each cell has 3 choices
- Total possibilities ≈ `3^(3N)`
- Exponential → impossible even for small `N`

❌ **Rejected**

---

## ❌ Approach 1: DFS / Backtracking

### 🔹 Idea
Paint row by row using recursion.

### 🔹 Why it fails
- Still exponential
- Recomputes same patterns
- Even memoization is too slow

❌ **Rejected**

---

## ❌ Approach 2: Full DP on Grid

### 🔹 Idea
DP[row][color1][color2][color3]

### 🔹 Why it fails
- States = `N × 3 × 3 × 3`
- Transitions are heavy
- Unnecessary state explosion

❌ **Inefficient**

---

## ✅ Key Insight (Turning Point)

👉 **Exact colors do NOT matter — pattern structure does.**

Instead of tracking colors, we track **row types**.

---

## 🧠 Step 1: Valid Colorings of ONE Row

A row has 3 cells.

### Constraint:
- Adjacent cells must differ

---

### 🟦 Pattern Type 1: All Different (ABC)

Example:
```cpp
R G B
```

- All three cells have different colors
- Count:

```cpp
3 × 2 × 1 = 6
```

We call this **`diff` pattern**

---

### 🟩 Pattern Type 2: First & Third Same (ABA)

Example:
```cpp
R G R
```

- First ≠ second
- Second ≠ third
- First = third (allowed)

Count:
```cpp
3 × 2 = 6
```

We call this **`same` pattern**

---

### ✅ Total valid patterns per row

same + diff = 6 + 6 = 12


---

## 🧠 Step 2: Why Only These Two States Matter

Even though colors differ, **row structure repeats**.

So we define DP states:

same → number of rows with ABA pattern

diff → number of rows with ABC pattern


This is called **state compression**.

---

## 🔁 Step 3: Row-to-Row Transitions (CORE LOGIC)

We now check how one row can be placed above another **without vertical conflicts**.

After analysis:

### From `same` row:
- Can form **3** new `same`
- Can form **2** new `diff`

### From `diff` row:
- Can form **2** new `same`
- Can form **2** new `diff`

---

## 🧮 DP Recurrence Relations

Let:
- `same[i]` = ABA patterns at row `i`
- `diff[i]` = ABC patterns at row `i`

Then:

same[i] = same[i-1] * 3 + diff[i-1] * 2

diff[i] = same[i-1] * 2 + diff[i-1] * 2

---

## 🧠 Base Case (Row 1)
same = 6

diff = 6


---

## 🧪 Dry Run

### N = 1

same = 6

diff = 6

answer = 12

### N = 2
same = 63 + 62 = 30

diff = 62 + 62 = 24

answer = 54


---

## 🕒 Time & Space Complexity

- **Time:** O(N)
- **Space:** O(1) (only previous row needed)

---

## 🧠 Key Learnings from This Problem

- Pattern-based DP
- State reduction
- Avoiding unnecessary dimensions
- Using constraints to simplify logic
- Handling HARD problems systematically

---


## 🧾 Pseudocode
```cpp
MOD = 10^9 + 7

// Base case for first row
same = 6     // ABA patterns
diff = 6     // ABC patterns

for row from 2 to N:
    newSame = (same * 3 + diff * 2) % MOD
    newDiff = (same * 2 + diff * 2) % MOD

    same = newSame
    diff = newDiff

return (same + diff) % MOD

```
### 📌 What this pseudocode shows clearly
* No grid stored
* Only 2 states tracked
* Row-by-row DP build
* Space optimized to O(1)

### 🧪 Dry Run (Step-by-Step, Expanded)
#### 🔹 Case 1: `N = 1`

Only one row.
```cpp
same = 6
diff = 6

answer = same + diff = 12
```

✔ Matches expected output.

#### 🔹 Case 2: `N = 2`

Start:
```cpp
same = 6
diff = 6
```

Row 2 transition:
```cpp
newSame = 6*3 + 6*2 = 18 + 12 = 30
newDiff = 6*2 + 6*2 = 12 + 12 = 24
```

Update:
```cpp
same = 30
diff = 24
```

Final answer:
```cpp
30 + 24 = 54
```

#### 🔹 Case 3: `N = 3` (Important for confidence)

Start row 2 result:
```cpp
same = 30
diff = 24
```

Row 3 transition:
```cpp
newSame = 30*3 + 24*2 = 90 + 48 = 138
newDiff = 30*2 + 24*2 = 60 + 48 = 108
```

Update:
```cpp
same = 138
diff = 108
```

Final answer:
```cpp
138 + 108 = 246
```

✔ Growth pattern clearly visible

✔ Confirms recurrence correctness

## ✅ Final Algorithm Summary
```cpp
same = 6
diff = 6

for i from 2 to N:
newSame = same * 3 + diff * 2
newDiff = same * 2 + diff * 2
same = newSame % MOD
diff = newDiff % MOD

return (same + diff) % MOD
```

---

📁 **Files in this folder:**
- `solution.cpp`
- `solution.java`
- `solution.py`
