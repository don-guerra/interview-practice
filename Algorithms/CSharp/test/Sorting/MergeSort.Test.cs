namespace Algorithms.Test.Sorting
{
    using System;
    using Algorithms.Sorting;
    using Xunit;

    public class MergeSortTest
    {
        private ISort<int> mergeSort;

        public MergeSortTest()
        {
            this.mergeSort = new MergeSort<int>();
        }

        [Fact]
        public void ShouldHandleAnEmptyArray()
        {
            var exception = Record.Exception(() => this.mergeSort.sortIncreasing(new int[] { }));
            Assert.Null(exception);
        }

        [Fact]
        public void ShouldReturnSortedArrayInDecreasingOrder()
        {
            int[] input = new int[] { 100, 9, 46, 2, 5, 3 };
            int[] expectedOutput = new int[] { 100, 46, 9, 5, 3, 2 };
            this.mergeSort.sortDecreasing(input);
            Assert.Equal(expectedOutput, input);
        }

        [Fact]
        public void ShouldReturnSortArray_IncreasingOrder()
        {
            int[] input = new int[] { 100, 9, 46, 2, 5, 3 };
            int[] expectedOutput = new int[] { 2, 3, 5, 9, 46, 100 };
            this.mergeSort.sortIncreasing(input);
            Assert.Equal(expectedOutput, input);
        }
    }
}
