namespace Algorithms.Sorting
{
    using System;

    public class BubbleSort<T> : ISort<T> where T : IComparable
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
                for (int j = 0; j < i; j++)
                {
                    if (HandleComparison(arr[i].CompareTo(arr[j])))
                    {
                        T temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
    }
}
