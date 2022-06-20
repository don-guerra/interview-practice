namespace Algorithms.MaximumSubarray
{
    using System;

    public class BruteForceMaximumSubarraySolver : IMaximumSubarraySolver
    {
        public Result solve(int[] input)
        {
            int maxSum = int.MinValue;
            int smallIndex = -1;
            int highIndex = -1;
            for (int i = 0; i < input.Length; i++)
            {
                int sum = 0;
                for (int j = i; j < input.Length; j++)
                {
                    sum = input[j] + sum;
                    if (sum > maxSum)
                    {
                        smallIndex = i;
                        highIndex = j;
                        maxSum = sum;
                    }
                }
            }

            if (maxSum == int.MinValue)
            {
                maxSum = 0;
            }

            return new Result()
            {
                indices = new Tuple<int, int>(smallIndex, highIndex),
                sum = maxSum
            };
        }
    }
}
