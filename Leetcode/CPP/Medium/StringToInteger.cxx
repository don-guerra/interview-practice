// Problem can be found at: https://leetcode.com/problems/string-to-integer-atoi/

#include <string>
#include "../ConsoleLogger.hxx"

bool isNumber(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }

    return false;
}

int myAtoi(std::string s)
{
    int index = 0;
    bool isNegative = false;

    // Ignoring any leading characters
    while (index < s.size() && s[index] == ' ')
    {
        index++;
    }

    // Reading the next character to determine if it is a pos(+) or neg(-) number
    // If it is we move the index forward as it was a valid character
    if (index < s.size() && (s[index] == '-' || s[index] == '+'))
    {
        isNegative = s[index++] == '-' ? true : false;
    }

    // Iterating through the rest of the string
    int num = 0;
    while (index < s.size())
    {
        if (!isNumber(s[index]))
            break;

        int val = s[index] - '0';
        if (num > (INT32_MAX / 10) || (val > (INT32_MAX % 10) && num == (INT32_MAX / 10)))
        {
            return isNegative ? INT32_MIN : INT32_MAX;
        }

        num = num * 10 + val;
        index++;
    }

    num = isNegative ? num * -1 : num;
    return num;
}

int main()
{
    printResult("First Result", myAtoi("42"));
    printResult("Second Result", myAtoi("-42"));
    printResult("Third Result", myAtoi("+42"));
    printResult("Fourth Result", myAtoi("4193 with words"));
    printResult("Fifth Result", myAtoi("words and 987"));
    printResult("Sixth Result", myAtoi("-91283472332"));
    printResult("Seventh Result", myAtoi("21474836460"));
    printResult("Eight Result", myAtoi("-20"));

    return 0;
}
