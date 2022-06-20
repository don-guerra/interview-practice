namespace Algorithms.MaximumSubarray
{
    using System;

    public record Result
    {
        public Tuple<int, int> indices { get; init; }

        public int sum { get; init; }
    }

    public interface IMaximumSubarraySolver
    {
        Result solve(int[] input);
    }
}
