# [Intersection of Two Array II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## Problem Statement
Given two arrays, write a function to compute their intersection.

#### Example 1
```
Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
Output: [2, 2]
```

#### Example 2
```
Input: nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
Output: [4, 9]
```

**Note: Each element in the result should appear as many time as it shows in both arrays**
**Note: The result can be in any order**

## Thought on solving the problem

### First Iteration
Iterate through nums1 and keep track of the value that occurr and the number of times in a hash map.
Then iterate through nums2 and if we encounter an element that is in the hashmap we add it to the output array and subtract a value from the hashmap.
When the value in the hashmap for a given element reaches 0 we remove it from the map.
```
numsMap<int, int> = {}; // Key is the number and value is the number of times it occurred
output = []
for each element in nums1:
    if element in numsMap:
        numsMap[element]++
    else:
        numsMap[element] = 0

for each element in nums2:
    if element in numsMap:
        output insert element
        numsMap[element]--
        if (numsMap[element] <= 0)
            remove element from element

return output;
```