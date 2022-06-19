namespace Algorithms.Test.Sorting
{
    using Algorithms.Sorting;
    using Xunit;

    public class SortTestInstances : TheoryData<ISort<int>>
    {
        public SortTestInstances()
        {
            Add(new MergeSort<int>());
            Add(new InsertionSort<int>());
            Add(new BubbleSort<int>());
        }
    }

    public class MergeSortTest
    {
        [Theory]
        [ClassData(typeof(SortTestInstances))]
        public void ShouldHandleAnEmptyArrayWhenDecreasing(ISort<int> instance)
        {
            var exception = Record.Exception(() => instance.sortDecreasing(new int[] { }));
            Assert.Null(exception);
        }

        [Theory]
        [ClassData(typeof(SortTestInstances))]
        public void ShouldHandleAnEmptyArrayWhenIncreasing(ISort<int> instance)
        {
            var exception = Record.Exception(() => instance.sortIncreasing(new int[] { }));
            Assert.Null(exception);
        }

        [Theory]
        [ClassData(typeof(SortTestInstances))]
        public void ShouldReturnSortedArrayInDecreasingOrder(ISort<int> instance)
        {
            int[] input = new int[] { 100, 9, 46, 2, 5, 3 };
            int[] expectedOutput = new int[] { 100, 46, 9, 5, 3, 2 };
            instance.sortDecreasing(input);
            Assert.Equal(expectedOutput, input);
        }

        [Theory]
        [ClassData(typeof(SortTestInstances))]
        public void ShouldReturnSortArray_IncreasingOrder(ISort<int> instance)
        {
            int[] input = new int[] { 100, 9, 46, 2, 5, 3 };
            int[] expectedOutput = new int[] { 2, 3, 5, 9, 46, 100 };
            instance.sortIncreasing(input);
            Assert.Equal(expectedOutput, input);
        }
    }
}
