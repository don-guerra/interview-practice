#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::map<int, int> numsMap; // <value, num times>
    std::map<int, int>::iterator numsMapIt;
    std::vector<int> result;

    for (int i = 0; i < nums1.size(); i++)
    {
        numsMapIt = numsMap.find(nums1[i]);
        numsMap[nums1[i]] = (numsMap.end() == numsMapIt) ? 1 : numsMapIt->second + 1;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        numsMapIt = numsMap.find(nums2[i]);
        if (numsMap.end() != numsMapIt)
        {
            result.push_back(nums2[i]);
            if (--(numsMapIt->second) <= 0)
            {
                numsMap.erase(numsMapIt);
            }
        }
    }

    return result;
}

std::vector<int> intersect2(std::vector<int> &nums1, std::vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int nums1Ptr = 0;
    int nums2Ptr = 0;
    std::vector<int> output;
    while (nums1Ptr < nums1.size() && nums2Ptr < nums2.size())
    {
        if (nums1[nums1Ptr] == nums2[nums2Ptr])
        {
            output.push_back(nums1[nums1Ptr]);
            nums1Ptr++;
            nums2Ptr++;
        }
        else if (nums1[nums1Ptr] < nums2[nums2Ptr])
        {
            nums1Ptr++;
        }
        else
        {
            nums2Ptr++;
        }
    }

    return output;
}

void printResult(std::string label, std::vector<int> &result)
{
    printf("%s", label.c_str());
    for (int i = 0; i < result.size(); i++)
    {
        printf(" %d", result[i]);
    }

    printf("\n");
}

int main()
{
    std::vector<int> nums1{1, 2, 2, 1};
    std::vector<int> nums2{2, 2};
    std::vector<int> result = intersect2(nums1, nums2);
    printResult("First Result:", result);

    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    result = intersect2(nums1, nums2);
    printResult("First Result:", result);

    return 0;
}