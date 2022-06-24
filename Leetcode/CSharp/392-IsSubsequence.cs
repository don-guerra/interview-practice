public class Solution
{
    public bool IsSubsequence(string s, string t)
    {
        int sIndex = 0;
        int tIndex = 0;

        while (sIndex < s.Length && tIndex < t.Length)
        {
            if (t[tIndex] == s[sIndex])
            {
                sIndex++;
            }

            tIndex++;
        }

        return sIndex == s.Length;
    }
}
