/*
* Problem can be found here: https://leetcode.com/problems/reverse-integer
*/

#include <string>
#include "../ConsoleLogger.hxx"

int reverseStl(int x)
{
    try
    {
        std::string numStr = std::to_string(x);

        for (int i = 0; i < numStr.length() / 2; i++)
        {
            char temp = numStr[i];
            numStr[i] = numStr[numStr.length() - 1 - i];
            numStr[numStr.length() - 1 - i] = temp;
        }

        return (x >= 0) ? std::stoi(numStr) : 0 - std::stoi(numStr);
    }
    catch (std::out_of_range)
    {
        return 0;
    }
}

int reverse(int x)
{
    try
    {
        int output = 0;
        while (x != 0)
        {
            int val = x % 10;
            x /= 10;

            if (output > INT32_MAX / 10)
                return 0;
            if (output < INT32_MIN / 10)
                return 0;

            output = output * 10 + val;
        }

        return output;
    }
    catch (const std::out_of_range &e)
    {
        return 0;
    }
}

int main()
{
    printResult("First result", reverse(321));
    printResult("Second result", reverse(-321));
    printResult("Third result", reverse(1534236469));
}