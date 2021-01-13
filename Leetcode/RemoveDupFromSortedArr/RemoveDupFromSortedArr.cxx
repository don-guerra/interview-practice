#include <stdio.h>
#include <set>
#include <vector>
#include <string>

int removeDuplicates(std::vector<int> &nums)
{
    std::set<int> numSet;
    int index = 0;
    while (index < nums.size())
    {
        std::set<int>::iterator it = numSet.find(nums[index]);
        if (numSet.end() == it)
        {
            numSet.insert(nums[index]);
            index++;
        }
        else
        {
            nums.erase(nums.begin() + index);
        }
    }

    return nums.size();
}

void printResult(std::string label, std::vector<int> &nums)
{
    printf("%s\t", label.c_str());
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d\t", nums[i]);
    }

    printf("\n");
}

int main()
{
    std::vector<int> nums{1, 1, 2};
    removeDuplicates(nums);
    printResult("First Result:", nums);

    nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    removeDuplicates(nums);
    printResult("Second Result:", nums);

    return 0;
}
