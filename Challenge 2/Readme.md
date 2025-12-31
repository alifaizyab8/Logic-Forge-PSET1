# Challenge 2: *Password Recovery Window*

---

You are given two strings:

- `log` → a string representing system activity
- `pattern` → characters required to recover a password

Your task is to find the **smallest continuous substring of `log`** that contains **all characters of `pattern`**, including **duplicate characters**.

If no such substring exists, return an empty string `""`.

### Function Requirement

> Write a function that takes two strings log and pattern and returns the minimum window substring of log. If no valid window exists, return an empty string.
> 

- **Rules:**
    - The order of characters does **not** matter
    - The substring must be **continuous**
    - The answer will be **unique** if it exists

---

- Examples
    
    **Example 1**
    
    Input:  log = "ADOBECODEBANC", pattern = "ABC"
    Output: "BANC"
    **Example 2**
    
    Input:  log = "a", pattern = "a"
    Output: "a"
    **Example 3**
    
    Input:  log = "a", pattern = "aa"
    Output: ""
    

---

- Constraints
    - `1 ≤ len(log), len(pattern) ≤ 10⁵`
    - Strings contain uppercase and lowercase English letters

---

- Hint
    
    Use a **sliding window** approach:
    
    - Expand the window to include required characters
    - Shrink it to find the **minimum valid window**
    - Use character frequency counting
    
    **Target Complexity:** `O(m + n)`
    

##