namespace Algorithms.Sorting
{
    using System;

    public class MergeSort<T> : ISort<T> where T : IComparable<T>
    {
        public void sortIncreasing(T[] arr)
        {
            sort(0, arr.Length - 1, arr, (val) => val <= 0);
        }

        public void sortDecreasing(T[] arr)
        {
            sort(0, arr.Length - 1, arr, (val) => val > 0);
        }

        private void sort(int low, int high, T[] arr, Func<int, bool> handleComparison)
        {
            if (low < high)
            {
                int mid = (low + high) / 2;
                this.sort(low, mid, arr, handleComparison);
                this.sort(mid + 1, high, arr, handleComparison);
                this.merge(low, mid, high, arr, handleComparison);
            }
        }

        private void merge(int low, int mid, int high, T[] arr, Func<int, bool> handleComparison)
        {
            int numLeft = mid - low + 1;
            int numRight = high - mid;
            T[] left = new T[numLeft];
            T[] right = new T[numRight];

            // Copying left from [low ... mid]
            for (int i = 0; i < numLeft; i++)
            {
                left[i] = arr[low + i];
            }

            // Copying right from [mid + 1 ... high]
            for (int i = 0; i < numRight; i++)
            {
                right[i] = arr[mid + 1 + i];
            }

            // Compare top of each array
            int leftPtr = 0;
            int rightPtr = 0;
            int storeIndex = low;
            while (leftPtr < numLeft && rightPtr < numRight)
            {
                if (handleComparison(left[leftPtr].CompareTo(right[rightPtr])))
                {
                    arr[storeIndex] = left[leftPtr++];
                }
                else
                {
                    arr[storeIndex] = right[rightPtr++];
                }
                storeIndex++;
            }

            // Copy over remainder of elements in the left array
            while (leftPtr < numLeft)
            {
                arr[storeIndex] = left[leftPtr++];
                storeIndex++;
            }

            // Copy over remainder of elements in the right array
            while (rightPtr < numRight)
            {
                arr[storeIndex] = right[rightPtr++];
                storeIndex++;
            }
        }
    }
}
