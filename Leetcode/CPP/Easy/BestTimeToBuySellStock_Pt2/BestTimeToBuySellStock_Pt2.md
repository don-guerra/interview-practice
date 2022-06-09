# [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Problem Statement
Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

**Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).**

#### Example 1
```
Input: [7, 1, 5, 3, 6, 4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 4
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit 3
```

#### Example 2
```
Input: [1, 2, 3, 4, 5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 4
```

#### Example 3
```
Input: [7, 6, 4, 3, 1]
Output: 0
Explanation: No transaction is done since buy on any day will lead to a negative profit.
```

## Thoughts on solving the problem

### First Iteration
If we plot this on a graph we notice that we can have something like:
```
|
|    /
| /\/
|/_______
```
Where what we need to do is just add the slopes as we are incrementing so pretty much `prices[i]-prices[i-1]`.

So if we take Example 1 from above:
```
[7, 1, 5, 3, 6, 4]
prices[1] < prices[0] so we don't add to profit
prices[2] > prices[1] so we add to profit -->  profit = 4
prices[3] > prices[2] so we don't add to profit
.... and so on as we only care about positive gains when they occur
```

