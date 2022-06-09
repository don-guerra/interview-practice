#include <stdio.h>
#include <vector>
#include <set>

bool containsDuplicate(std::vector<int> &nums)
{
    std::set<int> numSet;
    for (int i = 0; i < nums.size(); i++)
    {
        std::set<int>::iterator it = numSet.find(nums[i]);
        if (numSet.end() == it)
        {
            numSet.insert(nums[i]);
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 1};
    printf("First Result: %d\n", containsDuplicate(nums));

    nums = {1, 2, 3, 4};
    printf("Second Result: %d\n", containsDuplicate(nums));
}