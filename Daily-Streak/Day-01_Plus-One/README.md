# Day 01 – Plus One

🔗 **Problem Link:**  
https://leetcode.com/problems/plus-one/description/?envType=daily-question&envId=2026-01-01

---

## 📌 Problem Statement (Brief)

You are given a **large integer represented as an array of digits**, where each digit is in the range `[0–9]`.  
The digits are ordered from **most significant to least significant**.

Your task is to **increment the number by one** and return the resulting digits as an array.

---

## 🧠 Topics & Concepts Involved

- Arrays / Vectors
- Basic Mathematics
- Carry Handling
- Edge Case Analysis
- Simulation
- Reverse Traversal

---

## 🎯 Key Observations

- The number is stored digit-by-digit.
- Adding `1` may:
  - Simply increase the last digit
  - OR cause a **carry** (e.g., `9 + 1 = 10`)
- Carry can propagate leftwards.
- If all digits are `9`, the result will have **one extra digit**.

---

## 💡 Intuition

Start adding `1` from the **last digit** (least significant digit), just like we do in normal addition.

- If the digit is less than `9`, increment it and stop.
- If the digit is `9`, make it `0` and carry forward.
- If carry reaches beyond the first digit, add `1` at the beginning.

This simulates **manual addition**.

---

## 🧩 Approach 1: Iterative Carry Handling (Optimal)

### 🔹 Explanation

1. Traverse the array from **right to left**.
2. Add `1` to the current digit.
3. If digit becomes `10`:
   - Set it to `0`
   - Continue carry
4. Else:
   - No carry → return the array immediately
5. If all digits were `9`, insert `1` at the front.

---

### 🧪 Dry Run

#### Example 1
Input: 
```cpp
[1, 2, 3]
```

Process:

* Start from last digit: 3 + 1 = 4
Output: 
```cpp
[1, 2, 4]
```

#### Example 2
Input: 
```cpp
[9, 9, 9]
```
Process:

* 9 + 1 → 0 (carry)
* 9 + 1 → 0 (carry)
* 9 + 1 → 0 (carry)
* Carry remains → add 1 at front

Output: 
```cpp
[1, 0, 0, 0]
```


---

## 🕒 Time & Space Complexity

- **Time Complexity:** `O(n)`
  - In worst case, we traverse all digits once.
- **Space Complexity:** `O(1)`
  - No extra space (except when adding one digit in worst case).

---

## ⚠️ Common Mistakes

- Forgetting to handle the case where **all digits are 9**
- Traversing from left instead of right
- Using integer conversion (may overflow for large inputs)
- Creating unnecessary extra arrays

---

## 🧠 What This Problem Teaches

- How to simulate arithmetic operations using arrays
- Importance of handling edge cases
- Carry propagation logic
- Writing clean, optimal iterative solutions

---

## ✅ Summary

- Simple problem, but tests **edge-case thinking**
- Best solved using **reverse traversal**
- Common interview warm-up problem
- Foundation for problems involving **digit manipulation**

---

📁 **Files in this folder:**
- `solution.cpp` → C++ implementation
- `solution.java` → Java implementation
- `solution.py` → Python implementation