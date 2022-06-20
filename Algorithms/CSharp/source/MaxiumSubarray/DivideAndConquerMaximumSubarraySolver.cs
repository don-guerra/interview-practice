namespace Algorithms.MaximumSubarray
{
    using System;

    public class DivideAndConquerMaximumSubarraySolver : IMaximumSubarraySolver
    {
        public Result solve(int[] input)
        {
            if (input.Length <= 0)
            {
                return new Result() { indices = new Tuple<int, int>(-1, -1), sum = 0 };
            }
            return recurse(0, input.Length - 1, input);
        }

        private Result recurse(int lowIndex, int highIndex, int[] input)
        {
            if (lowIndex >= highIndex)
            {
                return new Result()
                {
                    indices = new Tuple<int, int>(lowIndex, highIndex),
                    sum = input[lowIndex]
                };
            }
            else
            {
                int mid = (lowIndex + highIndex) / 2;
                Result leftResult = recurse(lowIndex, mid, input);
                Result rightResult = recurse(mid + 1, highIndex, input);
                Result crossMidResult = GetMaximumCrossingSubArray(lowIndex, mid, highIndex, input);

                if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossMidResult.sum)
                {
                    return leftResult;
                }
                else if (rightResult.sum >= crossMidResult.sum)
                {
                    return rightResult;
                }
                else
                {
                    return crossMidResult;
                }
            }
        }

        /// <summary>
        /// Calculates the maximum subarray goes from [lowIndex...highIndex]
        /// <summary>
        private Result GetMaximumCrossingSubArray(
            int lowIndex,
            int midIndex,
            int highIndex,
            int[] input
        )
        {
            int sum = 0;
            int maxLeftSum = int.MinValue;
            int maxRightSum = int.MinValue;
            int leftIndex = -1;
            int rightIndex = -1;

            // Calculating the max subarray on the left-handside
            for (int i = midIndex; i >= lowIndex; i--)
            {
                sum += input[i];
                if (sum > maxLeftSum)
                {
                    maxLeftSum = sum;
                    leftIndex = i;
                }
            }

            // Calculating the max subarray on the right-handside
            sum = 0;
            for (int i = midIndex + 1; i <= highIndex; i++)
            {
                sum += input[i];
                if (sum > maxRightSum)
                {
                    maxRightSum = sum;
                    rightIndex = i;
                }
            }

            return new Result
            {
                sum = maxLeftSum + maxRightSum,
                indices = new Tuple<int, int>(leftIndex, rightIndex)
            };
        }
    }
}
