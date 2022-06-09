# [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

## Problem Statement
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#### Example 1
```
Input: [1, 2, 3, 1]
Output: true
```

## Thoughts on solving the problem

### First Iteration
There is a brute force implementation where we can iterate through every element twice using a double for loop. 
```
for (int i = 0; i < input.size(); i++) {
    for (int j = i + 1; j < input.size(); j++) {
        if (input[i] == input[j]) {
            return true;
        }
    }
}

return false;
```
While this solution works it is not the most optimal solution since in the worst case the runtime complexity is O(n^2).

The better solution would have been to store elements in a set as we pass through. If there is a duplicate the element would exist in the set and if not then we store the element into the set.
```
std::set<int> numSet
for each element in the input:
    if element in set:
        return true
    else 
        numSet.insert(element)
```

Runtime complexity: O(n) --> worst case we iterate through every element once
Space complexity: O(n) --> worst case we store every element in the set