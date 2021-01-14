#include <stdio.h>
#include <vector>
#include <string>

void rotate(std::vector<int> &nums, int k)
{
    std::vector<int> temp(nums);
    for (int i = 0; i < temp.size(); i++)
    {
        int newIndex = (i + k) % nums.size();
        nums[newIndex] = temp[i];
    }
}

void printResult(std::string label, std::vector<int> &nums)
{
    printf("%s:\t", label.c_str());
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    printResult("First Result", nums);

    return 0;
}