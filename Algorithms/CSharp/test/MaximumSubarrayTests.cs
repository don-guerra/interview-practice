namespace Algorithms.Test
{
    using Algorithms.MaximumSubarray;
    using Xunit;

    public class MaximumSubarrayTestInstances : TheoryData<IMaximumSubarraySolver>
    {
        public MaximumSubarrayTestInstances()
        {
            Add(new BruteForceMaximumSubarraySolver());
            Add(new DivideAndConquerMaximumSubarraySolver());
        }
    }

    public class MaximumSubarrayTests
    {
        [Theory]
        [ClassData(typeof(MaximumSubarrayTestInstances))]
        public void ShouldReturnTheLargestSum(IMaximumSubarraySolver instance)
        {
            var output = instance.solve(
                new int[] { -13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 }
            );
            Assert.Equal(43, output.sum);
            Assert.Equal(7, output.indices.Item1);
            Assert.Equal(10, output.indices.Item2);
        }

        [Theory]
        [ClassData(typeof(MaximumSubarrayTestInstances))]
        public void ShouldReturnTheLargestValue_WhenInputOnlyHasNegativeNumbers(
            IMaximumSubarraySolver instance
        )
        {
            var output = instance.solve(new int[] { -13, -12, -1, -43 });
            Assert.Equal(-1, output.sum);
            Assert.Equal(2, output.indices.Item1);
            Assert.Equal(2, output.indices.Item2);
        }

        [Theory]
        [ClassData(typeof(MaximumSubarrayTestInstances))]
        public void ShouldHandleAnEmptyArray(IMaximumSubarraySolver instance)
        {
            var output = instance.solve(new int[] { });
            Assert.Equal(0, output.sum);
            Assert.Equal(-1, output.indices.Item2);
            Assert.Equal(-1, output.indices.Item1);
        }
    }
}
