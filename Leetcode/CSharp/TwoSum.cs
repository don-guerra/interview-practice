public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        return OptimizedSolution(nums, target);
    }

    public int[] NaiveSolution(int[] nums, int target) {
        int[] output = new int[2];

        for (int i = 0; i < nums.Length; i++) {
            for (int j = i + 1; j < nums.Length; j++) {
                if (nums[i] + nums[j] == target) {
                    output[0] = i;
                    output[1] = j;
                    break;
                }
            }
        }

        return output;
    }

    public int[] OptimizedSolution(int[] nums, int target) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        int[] output = new int[2];

        for (int i = 0; i < nums.Length; i++) {
            int dictValue = 0;
            if (dict.TryGetValue(nums[i], out dictValue)) {
                output[0] = dictValue;
                output[1] = i;
                break;
            }

            dict.TryAdd(target - nums[i], i);
        }

        return output;
    }
}