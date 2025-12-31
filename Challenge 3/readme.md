# *Challenge 3: Balanced Performance Score*

---

Two student teams worked on the **same coding lab**, but their scores were recorded **separately** and are already **sorted**.

You are given:

- `scoresA` → sorted scores of Team A
- `scoresB` → sorted scores of Team B

Your task is to find the **median score** after considering **both teams together**.

⚠️ You are **not allowed to fully merge** the two lists.

---

### 🧩 Problem Statement/ Function Requirement

> Write a function that takes two sorted integer arrays scoresA and scoresB and returns the median value as a floating-point number.
> 

The solution must run in:

> O(m + n) time
> 

---

- Examples
    
    **Example 1**
    
    ```
    Input:  scoresA = [1, 3], scoresB = [2]
    Output: 2.0
    
    ```
    
    **Example 2**
    
    ```
    Input:  scoresA = [1, 2], scoresB = [3, 4]
    Output: 2.5
    Explanation 
    ```
    
    ---
    
    - If the total number of elements is **odd**, the median is the **middle value**
    - If **even**, the median is the **average of the two middle values**

---

- Constraints
    
    `0 ≤ m, n ≤ 1000` 
    
    `1 ≤ m + n ≤ 2000` 
    
    Arrays are already **sorted**
    
    Values range from `10⁶` to `10⁶`
    

---

- Hint
    
    Use **two-pointer traversal** approach:
    
    - Start with one pointer at the beginning of each array
    - Move the pointer with the smaller current value
    - Keep a count of how many elements have been seen
    - Stop when you reach the median position
    
    You do **not** need to store the merged array. You may simulate merging using indices, but must not create a merged array.