[Rotate Array](https://leetcode.com/problems/rotate-array/)

## Problem
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?

### Example 1
```
Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]
```

### Example 2
```
Input: nums = [-1, -100, 3, 99], k = 2
Output: [3, 99, -1, 100]
```

## Thoughts on solving the problem

### First Iteration
The index calculation after rotation can be calculated as:
```
newIndex = (oldIndex + k) % nums.size()

Let's say we have nums = [1, 2, 3, 4, 5, 6, 7], k = 3
The newIndex for 2 = (1+3) % 7 = 4
The newIndex for 7 = (6+3) % 7 = 2
```
Then to create the array we can just iterate through the initial nums array and store elements with their new index.

Runtime Complexity: O(n) iterate through each element once
Space Complexity: O(n) make an exact copy of the input array
