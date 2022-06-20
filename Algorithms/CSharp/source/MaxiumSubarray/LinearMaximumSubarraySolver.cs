namespace Algorithms.MaximumSubarray
{
    using System;

    public class LinearMaximumSubarraySolver : IMaximumSubarraySolver
    {
        public Result solve(int[] input)
        {
            if (input.Length <= 0)
            {
                return new Result() { indices = new Tuple<int, int>(-1, -1), sum = 0 };
            }

            int leftPtr = 0;
            int rightPtr = 0;
            int maxSum = input[0];
            int currentSum = input[0];
            for (int i = 0; i < input.Length; i++)
            {
                currentSum += input[i];
                if (input[i] > currentSum)
                {
                    currentSum = input[i];
                    leftPtr = i;
                }

                if (currentSum > maxSum)
                {
                    maxSum = currentSum;
                    rightPtr = i;
                }
            }

            return new Result() { indices = new Tuple<int, int>(leftPtr, rightPtr), sum = maxSum };
        }
    }
}
