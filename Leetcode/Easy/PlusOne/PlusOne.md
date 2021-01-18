# [Plus One]()

## Problem Statement
Given a non-empty array of decimal digits a non-negative integer, increment one integer.

The digits are stored such that the most significatn digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

#### Example 1
```
Input: digits = [1, 2, 3]
Output: [1, 2, 4]
```

## Thoughts on solving the problem

### First Iteration
The problem is quite simple we just need to add a single digit, and we can accomplish this the same way basic arithmetic is applied. When we add a number we start from the least significant digit and move towards the most significant digit. 
```
 100
+  1
----
 101

  109
+   1
-----
  110
```

Since the problem states that index 0 is the most significant digit, then we need to start from input[n-1], where n is the size of the input array, and add one to the digit. If after the addition, we have a value of zero we need to move down one index in the array and add one. We repeat this process until the result at the array position is not 0.

If we repeat the process until first index of the array (the most significant digit) then we need to store `1` to the front of the array.