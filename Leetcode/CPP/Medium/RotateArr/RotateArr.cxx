#include <stdio.h>
#include <vector>
#include <string>

void printResult(std::string label, std::vector<int> &nums)
{
    printf("%s:\t", label.c_str());
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}

void rotate(std::vector<int> &nums, int k)
{
    int visited = 0;
    int startIndex = 0;
    while (visited < nums.size())
    {
        int currentIndex = startIndex;
        int value = nums[startIndex];
        do
        {
            int nextIndex = (currentIndex + k) % nums.size();
            int temp = nums[nextIndex];
            nums[nextIndex] = value;
            value = temp;
            currentIndex = nextIndex;
            visited++;
        } while (currentIndex != startIndex);

        startIndex++;
    }
}

int main()
{
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    printResult("First Result", nums);

    nums = {-1, -100, 3, 99};
    rotate(nums, 2);

    return 0;
}