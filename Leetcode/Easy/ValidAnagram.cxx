/*
* Problem can be found at: https://leetcode.com/problems/valid-anagram/
*/

#include <string>
#include <map>
#include "../ConsoleLogger.hxx"

// Given two strings s and t, write a function to determine if t is an anagram of s
// Note: You may assume the string contains only lowercase alphabets
bool isAnagram(std::string s, std::string t)
{
    // Maintain an array of characters - 26 alphabet letter (since they are guaranteed to be just lower case character)
    int charCnt[26] = {0};

    // Iterate through the first string and increment the number of char we find
    for (int i = 0; i < s.size(); i++)
    {
        int charIndex = s[i] - 'a';
        charCnt[charIndex]++;
    }

    // Iterate through the second string and decrement the number of char we find
    // If we encounter a letter whose count is still 0 that means it was not present in the first string. Return false
    for (int i = 0; i < t.size(); i++)
    {
        int charIndex = t[i] - 'a';
        if (charCnt[charIndex] == 0)
        {
            return false;
        }
        else
        {
            charCnt[charIndex]--;
        }
    }

    // Go through the char array and ensure that the value of each entry is zero
    // If we find a non-zero value that means don't have the same number of chars in both strings -> Return false
    for (int i = 0; i < 26; i++)
    {
        if (charCnt[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    printResult("First Result", isAnagram("anagram", "nagaram"));
    printResult("Second Result", isAnagram("rat", "car"));
    return 0;
}