// Problem can be found at: https://leetcode.com/problems/valid-palindrome/

#include <string>
#include "../ConsoleLogger.hxx"

// Given a string, determine it is a palindrome, considering only alphanumeric characters
bool isPalindrome(std::string s)
{
    // Use a ptr to the end of the string that moves toward the front of the string
    // Use a ptr to the front of the string that moves torward the end of the string
    int frontPtr = 0;
    int endPtr = s.size() - 1;
    while (frontPtr < endPtr)
    {
        // Continue forward if it is not an alphanumeric character
        if (!std::isalnum(s[frontPtr]))
        {
            frontPtr++;
            continue;
        }

        // Continue forward if it is not an alphanumeric character
        if (!std::isalnum(s[endPtr]))
        {
            endPtr--;
            continue;
        }

        // Convert to lower case letter it is an upper or lowercase letter
        char frontChar = std::isalpha(s[frontPtr]) ? std::tolower(s[frontPtr]) : s[frontPtr];
        char endChar = std::isalpha(s[endPtr]) ? std::tolower(s[endPtr]) : s[endPtr];
        if (frontChar != endChar)
        {
            return false;
        }

        frontPtr++;
        endPtr--;
    }

    return true;
}

int main()
{
    printResult("First Result", isPalindrome("A man, a plan, a canal: Panama"));
    printResult("Second Result", isPalindrome("race a car"));
    return 0;
}
