#include <stdio.h>
#include <vector>
#include <string>

std::vector<int> plusOne(std::vector<int> &digits)
{
    std::vector<int> output(digits);
    int index = 0;
    for (index = output.size() - 1; index >= 0; index--)
    {
        if (output[index] != 9)
        {
            output[index]++;
            break;
        }
        else
        {
            output[index] = 0;
        }
    }

    if (index == -1)
    {
        output.insert(output.begin(), 1);
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
    std::vector<int> digits{1, 2, 3};
    std::vector<int> result = plusOne(digits);
    printResult("First Result:", result);

    digits = {9, 9, 9};
    result = plusOne(digits);
    printResult("Second Result:", result);

    return 0;
}