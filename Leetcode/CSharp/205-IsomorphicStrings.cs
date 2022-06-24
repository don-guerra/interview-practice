public class Solution
{
    public bool IsIsomorphic(string s, string t)
    {
        if (s.Length != t.Length)
            return false;

        int index = 0;
        Dictionary<char, char> sMapping = new Dictionary<char, char>();
        HashSet<char> tMatched = new HashSet<char>();
        while (index < s.Length)
        {
            if (!sMapping.ContainsKey(s[index]) && !tMatched.Contains(t[index]))
            {
                sMapping.Add(s[index], t[index]);
                tMatched.Add(t[index]);
            }
            else if (!sMapping.ContainsKey(s[index]) || sMapping[s[index]] != t[index])
            {
                return false;
            }

            index++;
        }

        return true;
    }
}
