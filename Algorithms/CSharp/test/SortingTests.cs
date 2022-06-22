namespace Algorithms.Test
{
    using Algorithms.Sorting;
    using Xunit;

    public class SortingTestInstances : TheoryData<ISort<int>>
    {
        public SortingTestInstances()
        {
            Add(new MergeSort<int>());
            Add(new InsertionSort<int>());
            Add(new BubbleSort<int>());
            Add(new HeapSort<int>());
            Add(new QuickSort<int>());
        }
    }

    public class SortingTests
    {
        [Theory]
        [ClassData(typeof(SortingTestInstances))]
        public void ShouldHandleAnEmptyArrayWhenDecreasing(ISort<int> instance)
        {
            var exception = Record.Exception(() => instance.sortDecreasing(new int[] { }));
            Assert.Null(exception);
        }

        [Theory]
        [ClassData(typeof(SortingTestInstances))]
        public void ShouldHandleAnEmptyArrayWhenIncreasing(ISort<int> instance)
        {
            var exception = Record.Exception(() => instance.sortIncreasing(new int[] { }));
            Assert.Null(exception);
        }

        [Theory]
        [ClassData(typeof(SortingTestInstances))]
        public void ShouldReturnSortedArrayInDecreasingOrder(ISort<int> instance)
        {
            int[] input = new int[] { 2, 8, 7, 1, 3, 5, 6, 4 };
            int[] expectedOutput = new int[] { 8, 7, 6, 5, 4, 3, 2, 1 };
            instance.sortDecreasing(input);
            Assert.Equal(expectedOutput, input);
        }

        [Theory]
        [ClassData(typeof(SortingTestInstances))]
        public void ShouldReturnSortArray_IncreasingOrder(ISort<int> instance)
        {
            int[] input = new int[] { 100, 9, 1, 2, 46, 5, 3 };
            int[] expectedOutput = new int[] { 1, 2, 3, 5, 9, 46, 100 };
            instance.sortIncreasing(input);
            Assert.Equal(expectedOutput, input);
        }
    }
}
