#include <stdio.h>
#include <vector>
#include <set>

int singleNumber(std::vector<int> &nums)
{
    std::vector<int> temp(nums);
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
            numSet.erase(it);
        }
    }

    return *(numSet.begin());
}

int main()
{
    std::vector<int> nums = {2, 2, 1};
    printf("First Result: %d\n", singleNumber(nums));

    nums = {1};
    printf("Second Result: %d\n", singleNumber(nums));

    return 0;
}