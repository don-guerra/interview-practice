# [Check Array Formation Through Concatenation](https://leetcode.com/problems/check-array-formation-through-concatenation/)
**Difficulty: Easy**

## Problem Statement
You are given an array of **distinct** integers `arr` and an array of integer arrays `pieces`, where the integers in `pieces` are **distinct**. Your goal is to form `arr` by concatenating the arrays in `pieces` in any **order**. However, you are not allowed to reorder the integers in each array `pieces[i]`.

Return true if it is possible to form the array arr from pieces. Otherwise, return false.

#### Example 1
```
Input: arr = [85], pieces = [[85]]
Output: true
```

#### Example 2
```
Input: arr=[49, 18, 16], pieces = [[16, 18, 49]]
Output: false
Explanation: Unable to reorder the integers in pieces[0], where pieces[0] = [16, 18, 49]
```

#### Example 3
```
Input: arr = [91, 4, 64, 78], pieces = [[78], [4, 64], [91]]
Output: true
Explanation: We start with pieces[2], then concatenate pieces[1] and finally concatenate pieces[0]
```

## Thoughts on solving this problem

### First iteration
Since the arrays in `pieces` will be concatenated as is we can create a hashmap, where the key is the pieces[i][0] and the value is pieces[i]. We will do the construction of the map initially, and then we can validate the given `arr`.
```
for each array in pieces:
    piecesMap.push(array[0], array)
```

The validation of `arr` will consist of
```
while elements in arr
    initialKey = arr[i]
    if arr[i] exists in piecesMap:
        arrInPieces equals piecesMap(initialKey)

        iterate through arrInPieces and arr, until no more elements in arrInPieces or arr
            if value in arrInPieces is arr[i]
                increment i
            else
                return false

        if arrInPieces index does not equal end
            return false
        
        piecesMap remove initialKey

if piecesMap contains elements
    return false

return true
```

Runtime Complexity: O(n*m), where n is the number of elements in arr and m is the number of elements in pieces[i].
Reasoning: In the worst case scenario we would have to iterate through all elements in `arr`, and through all elements in pieces[i] to validate that it exists in `arr`.

----------




