public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        HashSet<int> set = new HashSet<int>();
        bool containsDup = false;
        foreach (int num in nums) {
            if (set.Contains(num)) {
                containsDup = true;
                break;
            }

            set.Add(num);
        }

        return containsDup;
    }
}