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

### Second Iteration
We can rotate the array in place if we keep track of how many items we have visited and swap in place. We just need to store the value, the index and the number of positions we have visited. We stop processing when the number of positions is equal to or greater than the size of the array. 

Now this simple approach works when we never hit the same index again. The issue arises when the same index is hit twice, pretty much when return to the initial index.

What we need to do instead repeat the process until we reach the start index. We pretty much need are fixing the number until we do i % k = j, where j is the current index we are visiting. For instance, initially we would be fixing the position of `i % k == 0` and when the start index equals the current index we increment and start fixing the positioning of elements that satisfy `i % k == 1`

```
startIndex = 0
visited = 0
while we haven't visited all the numbers:
    currentIndex = startIndex
    value = nums[currentIndex]
    do while the start index doesn't equal the current index:
        storeIndex = (k + currentIndex) % nums.size()
        temp = nums[storeIndex]
        nums[storeIndex] = value
        value = temp
        currentIndex = storeIndex
        visited++
    
    startIndex++
```
