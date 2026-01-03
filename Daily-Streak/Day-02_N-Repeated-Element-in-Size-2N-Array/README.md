# Day 02 – N Repeated Element in Size 2N Array

🟢 **Difficulty:** Easy

🔗 **Problem Link:**  
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02

---

## 📌 Problem Statement (Simplified)

You are given an integer array `nums` of length `2N`.

- There are **N + 1 unique elements**
- **One element is repeated exactly N times**
- All other elements appear **only once**

Your task is to **find and return the element that is repeated N times**.

---

## 🧠 Topics & Concepts Involved

- Arrays
- Frequency counting
- Hashing
- Mathematical observation
- Problem constraints analysis
- Optimized constant-time approaches

---

## 🔍 Key Observations (Very Important)

1. The array size is `2N`
2. Exactly **one number repeats N times**
3. All other numbers are unique
4. The repeated element must appear **multiple times close together**
   (because N occurrences are packed among 2N elements)

This allows **better-than-hashmap solutions**.

---

## 💡 Core Intuition

Instead of counting **all elements**, we can exploit the **problem structure**:

- Since one element appears **N times**,  
- In a relatively small array (`2N`),  
- That repeated element **must collide quickly** with another occurrence.

So:
- If we compare neighboring elements (or small gaps),
- We can detect the repeated element **early**.

---

## 🧩 Approach 1: Hash Set (Straightforward)

### 🔹 Idea
- Traverse the array
- Store elements in a set
- If an element already exists → it is the answer

### 🔹 Why it works
- The repeated element appears many times
- The first duplicate we encounter is guaranteed to be the answer

### 🧾 Pseudocode
create empty set S

for each element x in nums:

if x exists in S:

return x

add x to S


### 🕒 Complexity
- Time: O(n)
- Space: O(n)

📌 **Good for clarity, but not optimal in space**

---

## 🧩 Approach 2: Sorting (Observation-Based)

### 🔹 Idea
- Sort the array
- The repeated element will appear **consecutively**
- Return the first duplicate found

### 🧾 Pseudocode

sort nums

for i from 1 to n-1:

if nums[i] == nums[i-1]:

return nums[i]


### 🕒 Complexity
- Time: O(n log n)
- Space: O(1) or O(n) depending on sort

📌 **Simple but slower than necessary**

---

## 🧩 Approach 3: Optimal Observation (Most Important)

### 🔥 Key Insight

Since:
- One element appears N times
- Array length is 2N

👉 The repeated element **must appear at least twice within a distance of 3**.

So we only need to check:
- `nums[i] == nums[i+1]`
- `nums[i] == nums[i+2]`
- `nums[i] == nums[i+3]`

This guarantees detection.

---

### 🔹 Why this works (Interview Gold)

Because:
- You cannot place N identical elements in a 2N array
- Without at least two being close together

This avoids:
- Hashing
- Sorting
- Extra memory

---

### 🧾 Pseudocode (Optimal)

for i from 0 to n-4:

if nums[i] == nums[i+1]:

return nums[i]

if nums[i] == nums[i+2]:

return nums[i]

if nums[i] == nums[i+3]:

return nums[i]

return nums[n-1]


---

## 🧪 Dry Run

### Example
nput: [5,1,5,2,5,3,5,4]

N = 4

Check:

nums[0] == nums[2] → 5 == 5 ✔

Return 5


---

## 🕒 Time & Space Complexity (Optimal Approach)

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

✔ Best possible solution  
✔ Interview-preferred approach  

---

## ⚠️ Common Mistakes

- Overusing HashMap without thinking
- Ignoring constraints (`2N` size is a BIG hint)
- Writing unnecessary nested loops
- Assuming the repeated element is always adjacent

---

## 🧠 What This Problem Teaches

- How to use **constraints to optimize solutions**
- Thinking beyond brute force
- Observation-based problem solving
- Recognizing hidden patterns in array problems

---

## ✅ Final Summary

| Approach | Time | Space | Recommended |
|------|------|------|-----------|
| Hash Set | O(n) | O(n) | ❌ |
| Sorting | O(n log n) | O(1) | ❌ |
| Observation-based | O(n) | O(1) | ✅ |

📌 **Best choice:** Observation-based linear scan

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)

