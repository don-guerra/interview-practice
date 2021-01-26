/*
* Problem can be found at: https://leetcode.com/problems/move-zeroes/
*/

#include <iostream>
#include <algorithm>
#include "../../ConsoleLogger.hxx"

// Moves all 0s to the end of the vector while maintaining the order of the numbers
// We want this to be done in-place without creating a nums copy

void moveZeroes2(std::vector<int> &nums)
{
    // Builds on the first attempt
    // There is no need to re-visit numbers. We can swap positions as we go as the new position of the number will be the position right before it or earlier.
    // Keep track of the first 0 that happens and directly swapping it, and then incrementing a position.
    // If we find ourselves at a zero number we increment the index we visit
    // If we find ourselves at a non-zero number that is not the current position we swap and move the position forward.
    // If we find ourselves at a non-zero number that is our current visiting index we move position and index forward.
    // 0 1 0 3 12 --> initially position 0
    // 1 0 0 3 12 --> swap index 1 and index 0; position is now 1
    // 1 3 0 0 12 --> swap; position is now 2
    // 1 3 12 0 0 --> swap; position is now 3
    int position = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            continue;

        if (i != position)
        {
            nums[position] = nums[i];
            nums[i] = 0;
        }

        position++;
    }
}

void moveZeroes1(std::vector<int> &nums)
{
    // Keep track of the last time we had a zero and then swap positions with a non-zero item
    // 0 1 0 3 12 --> first 0 position is index 0
    // 1 0 0 3 12 --> swap index 1 and index 0; first zero postion is now index 1
    // 1 0 0 3 12 --> next non-zero number is index 3;
    // 1 3 0 0 12 --> swap index 3 with index 1; first zero position is now index 2
    // 1 3 12 0 0  ---> swap index 4 with index 2
    int index = 0;
    int indexOfFirstZero = nums.size();
    while (index < nums.size())
    {
        if (nums[index] == 0 && index < indexOfFirstZero)
        {
            indexOfFirstZero = index;
        }

        if (nums[index] != 0 && indexOfFirstZero < nums.size())
        {
            std::iter_swap(nums.begin() + index, nums.begin() + indexOfFirstZero);
            index = ++indexOfFirstZero;
            indexOfFirstZero = nums.size();
            continue;
        }

        index++;
    }
}

int main()
{
    std::vector<int> nums{0, 1, 0, 3, 12};
    moveZeroes2(nums);
    printVector("First Result", nums);

    nums = {0, 0, 1};
    moveZeroes2(nums);
    printVector("Second Result", nums);

    return 0;
}