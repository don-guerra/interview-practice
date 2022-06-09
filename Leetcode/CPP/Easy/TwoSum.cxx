/*
* Problem can be found here: https://leetcode.com/problems/two-sum/
*/

#include <vector>
#include <map>
#include "../ConsoleLogger.hxx"

// Obtain the indices of the two numbers such that they add up to target
// Assume each input has exactly one solution
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    // Maintain a map of the value and the index.
    // When we iterate through the numbers we subtract target from the current value.
    // Then check if the value exists in the map. If it does we have found our complement and can return the value
    // If it doesn't then we store the value of the current index in the map and continue.
    std::map<int, int> sums; // Map of value and the index

    for (int i = 0; i < nums.size(); i++)
    {
        int remainder = target - nums[i];
        std::map<int, int>::iterator it = sums.find(remainder);
        if (it != sums.end())
        {
            return {i, it->second};
        }

        sums[nums[i]] = i;
    }

    throw std::invalid_argument("Failed to find two sum solution");
}

int main()
{
    std::vector<int> nums{2, 7, 11, 15};
    std::vector<int> result = twoSum(nums, 49);

    printVector("First Result", result);

    nums = {3, 2, 4};
    result = twoSum(nums, 6);
    printVector("Second Result", result);

    return 0;
}