# Day 04 – Four Divisors  
🟡 **Difficulty:** Medium

🔗 **Problem Link:**  
https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04

---

## 📌 Problem Statement (Simplified)

You are given an integer array `nums`.

For each number in the array:
- Find **all its positive divisors**
- If the number has **exactly 4 divisors**, add the **sum of those 4 divisors** to the answer

Return the **total sum** for all such numbers.

---

## 🧠 Prerequisites (Must Know Before Solving)

Before solving this problem, you should be comfortable with:

### 🔹 Programming Basics
- Loops
- Conditional checks
- Using variables efficiently

### 🔹 Mathematical Concepts
- Divisors of a number
- Square root optimization
- Prime numbers
- Factor pairs

### 🔹 DSA Concepts
- Time complexity analysis
- Optimizing brute-force solutions
- Handling edge cases

---

## ❓ Why This Problem Is Medium

Although it looks simple, this problem becomes tricky because:
- Checking divisors naively is slow
- Numbers can be large
- Multiple numbers need to be processed
- You must **optimize divisor counting**

This problem tests your **math + optimization skills**.

---

## 🧩 Approach 1: Brute Force (Naive – Not Used)

### 🔹 Idea
For each number:
- Check all numbers from `1` to `n`
- Count divisors
- If count == 4, sum them

### 🔹 Pseudocode (Brute Force)
```cpp
for each number x in nums:
divisors = []
for i from 1 to x:
if x % i == 0:
add i to divisors
if size of divisors == 4:
add sum(divisors) to answer
```

### ❌ Why This Fails
- Time Complexity: **O(n × x)** → too slow
- Will TLE for large values

📌 This approach is **commented in code only for learning**.

---

## ✅ Key Observation (Turning Point)

A number has **exactly 4 divisors** if and only if:

### 🔹 Case 1:  
`n = p³` where `p` is a **prime number**

Divisors:
```cpp
1, p, p², p³ → 4 divisors
```

### 🔹 Case 2:  
`n = p × q` where `p` and `q` are **distinct primes**

Divisors:
```cpp
1, p, q, p×q → 4 divisors
```


👉 Any other number will have **more or fewer than 4 divisors**.

This observation allows a **much faster solution**.

---

## 🧠 Approach 2: Optimal Math-Based Solution (USED)

### 🔹 Idea
For each number:
- Try to find **divisor pairs up to √n**
- Count divisors carefully
- Stop early if divisors exceed 4

---

## 🧾 Pseudocode (Optimal)
```cpp
answer = 0

for each number x in nums:
divisors = empty set

for i from 1 to sqrt(x):
    if x % i == 0:
        add i
        add x / i

    if size of divisors > 4:
        break

if size of divisors == 4:
    answer += sum of divisors

return answer
```


---

## 🧪 Dry Run Example

### Input:
```cpp
nums = [21, 4, 7]
```

### Number = 21
Divisors:
```cpp
1, 3, 7, 21 → 4 divisors
Sum = 32
```


### Number = 4
Divisors:
```cpp
1, 2, 4 → only 3 divisors ❌
```

### Number = 7
Divisors:
```cpp
1, 7 → only 2 divisors ❌
```

### Final Answer:
```cpp
32
```


---

## ⚠️ Edge Cases to Handle

- Prime numbers → only 2 divisors
- Perfect squares → avoid double-counting √n
- Large numbers → stop early if divisors > 4
- Array with no valid numbers → return 0

---

## 🕒 Time & Space Complexity

- **Time Complexity:**  
  `O(n × √m)`  
  where `m` is the maximum number in the array

- **Space Complexity:**  
  `O(1)` extra space (only counters & sums)

---

## 🧠 What This Problem Teaches

- How to optimize divisor counting
- Importance of mathematical observations
- Turning brute force into efficient solutions
- Early termination techniques
- Clean separation of learning vs optimal code

---

## ✅ Code Strategy Used in This Repo (Important)

- ✅ **Optimal solution is ACTIVE and uncommented**
- 📝 **Brute-force / alternate approaches are commented**
- 📘 Code is written in a **human-readable, beginner-friendly style**
- 🎯 Interview-ready logic only

---

## 📂 Files in this folder

- 📄 [Solution.cpp](Solution.cpp)
- 📄 [Solution.java](Solution.java)
- 📄 [Solution.py](Solution.py)
