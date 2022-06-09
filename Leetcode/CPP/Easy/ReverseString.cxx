/*
* Problem can be found at: https://leetcode.com/problems/reverse-string/
*/

#include <vector>
#include "../ConsoleLogger.hxx"

void reverseString(std::vector<char> &s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
}

int main()
{
    std::vector<char> s{'h', 'e', 'l', 'l', 'o'};
    printVector("Before", s);
    reverseString(s);
    printVector("After", s);

    return 0;
}