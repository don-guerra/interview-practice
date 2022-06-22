namespace Algorithms.Sorting
{
    using System;

    public class QuickSort<T> : ISort<T> where T : IComparable
    {
        public void sortIncreasing(T[] arr)
        {
            quickSort(0, arr.Length - 1, arr, (val) => val < 0);
        }

        public void sortDecreasing(T[] arr)
        {
            quickSort(0, arr.Length - 1, arr, (val) => val > 0);
        }

        private void quickSort(int start, int end, T[] arr, Func<int, bool> handleComparison)
        {
            if (start < end)
            {
                int partitionIndex = partition(start, end, arr, handleComparison);
                quickSort(start, partitionIndex - 1, arr, handleComparison);
                quickSort(partitionIndex + 1, end, arr, handleComparison);
            }
        }

        private int partition(int start, int end, T[] arr, Func<int, bool> handleComparison)
        {
            T partitionVal = arr[end];
            int i = start;
            for (int j = start; j < end; j++)
            {
                if (handleComparison(arr[j].CompareTo(partitionVal)))
                {
                    T temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    i++;
                }
            }

            arr[end] = arr[i];
            arr[i] = partitionVal;
            return i;
        }
    }
}
