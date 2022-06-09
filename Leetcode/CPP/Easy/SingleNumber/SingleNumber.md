# [Single Number](https://leetcode.com/problems/single-number/)

## Problem Statement
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

#### Example 1
```
Input: nums = [2, 2, 1]
Output: 1
```

#### Example 2
Input: nums = [4, 1, 2, 1, 2]
Output: 4

#### Example 3
```
Input: nums = [1]
Output: 1
```

## Constraints
- `1 <= nums.length <= 3*10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`
- Each element in the array appears twice except for one element which appears only once

## Thoughts on solving the problem

### First Iteration
Iterate through the array and store elements in a set. If we happen to hit an element that exists in the set, then we remove the element from the set. Since elements are guaranteed to only appear twice except for one element, the last element found in the set would be our result.

```
numSet = {}
for each element in the nums:
    if element in numSet
        numSet.erase(element)
    else 
        numSet.insert(element)

return firstElementInNumSet;
```

### Second Iteration