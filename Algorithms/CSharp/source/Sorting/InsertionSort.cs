namespace Algorithms.Sorting
{
    using System;

    public class InsertionSort<T> : ISort<T> where T : IComparable
    {
        public void sortDecreasing(T[] arr)
        {
            sort(arr, (val) => val >= 0);
        }

        public void sortIncreasing(T[] arr)
        {
            sort(arr, (val) => val < 0);
        }

        private void sort(T[] arr, Func<int, bool> HandleComparison)
        {
            for (int i = 1; i < arr.Length; i++)
            {
                T currentVal = arr[i];
                int j = i - 1;
                while (j >= 0 && HandleComparison(currentVal.CompareTo(arr[j])))
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = currentVal;
            }
        }
    }
}
