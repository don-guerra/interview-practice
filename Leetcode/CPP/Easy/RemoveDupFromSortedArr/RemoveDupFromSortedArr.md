# [Remove Duplicates from Sorted Arra](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## Problem Statemen
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

```
Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

## Thoughts on solving the problem

### First iteration
The brute force implementation would be to use a double loop:
```
for elementI in nums:
    for elementJ in in nums:
        if elementI equals elementJ:
            remve elementJ
```

Yet we can improve this implementation as it would run in O(n^2), which is not ideal. 

We can actually accomplish this is one pass by using a set to store elements as we pass through the nums array.
```
numSet = {}
for element in nums:
    if element in numSet:
        remove element from nums
    else:
        add element into numSet
```