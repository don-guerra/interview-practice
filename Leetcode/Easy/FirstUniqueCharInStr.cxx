/*
* Problem can be found here: https://leetcode.com/problems/first-unique-character-in-a-string/
*/

#include <string>
#include <map>
#include "../ConsoleLogger.hxx"

// Find the index of the first non-repeating character in a string
int firstUniqChar(std::string s)
{

    // Using a map store the number of times a character repeats in the string.
    // Note: We can also use an array, which might be much faster on insert
    // The first loop iterates through the string and creates the map of character count
    // The second one iterates through the string and checks to see if in the map the count of chars is 1
    // If it is then we return the index as that char has only repeated once.
    // If not we continue to check all chars.
    std::map<char, int> charCount;
    std::map<char, int>::iterator it;
    for (int i = 0; i < s.length(); i++)
    {
        it = charCount.find(s[i]);
        if (it == charCount.end())
        {
            charCount[s[i]] = 1;
        }
        else
        {
            charCount[s[i]]++;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (charCount[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int cnt = firstUniqChar("leetcode");
    printResult("First Result", cnt);

    printResult("Second Result", firstUniqChar("loveleetcode"));
    return 0;
}