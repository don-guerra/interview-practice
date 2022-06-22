using System;

namespace Algorithms.Sorting
{
    public class HeapSort<T> : ISort<T> where T : IComparable
    {
        public void sortDecreasing(T[] arr)
        {
            buildMinHeap(arr);
            int heapSize = arr.Length;
            for (int i = arr.Length - 1; i >= 0; i--)
            {
                T temp = arr[i];
                arr[i] = arr[0];
                arr[0] = temp;
                minHeapify(arr, 0, --heapSize);
            }
        }

        public void sortIncreasing(T[] arr)
        {
            buildMaxHeap(arr);
            int heapSize = arr.Length;
            for (int i = arr.Length - 1; i >= 0; i--)
            {
                T temp = arr[i];
                arr[i] = arr[0];
                arr[0] = temp;
                maxHeapify(arr, 0, --heapSize);
            }
        }

        private void buildMaxHeap(T[] arr)
        {
            for (int i = (arr.Length / 2) - 1; i > 0; i--)
            {
                maxHeapify(arr, i, arr.Length);
            }
        }

        private void buildMinHeap(T[] arr)
        {
            for (int i = (arr.Length / 2) - 1; i >= 0; i--)
            {
                minHeapify(arr, i, arr.Length);
            }
        }

        private void maxHeapify(T[] arr, int nodeIndex, int heapSize)
        {
            heapify(arr, nodeIndex, heapSize, (val) => val > 0);
        }

        private void minHeapify(T[] arr, int nodeIndex, int heapSize)
        {
            heapify(arr, nodeIndex, heapSize, (val) => val < 0);
        }

        private void heapify(T[] arr, int nodeIndex, int heapSize, Func<int, bool> handleComparison)
        {
            int currentIndex = nodeIndex;
            while (currentIndex < heapSize)
            {
                int leftIndex = this.getLeftNodeIndex(currentIndex);
                int rightIndex = this.getRightNodeIndex(currentIndex);
                int largestNodeIndex = currentIndex;

                // Determine if left nod is larger
                if (
                    leftIndex < heapSize
                    && handleComparison(arr[leftIndex].CompareTo(arr[largestNodeIndex]))
                )
                {
                    largestNodeIndex = leftIndex;
                }

                // Determine if right node is larger
                if (
                    rightIndex < heapSize
                    && handleComparison(arr[rightIndex].CompareTo(arr[largestNodeIndex]))
                )
                {
                    largestNodeIndex = rightIndex;
                }

                // If the largest node is the current index we stop
                if (currentIndex == largestNodeIndex)
                {
                    break;
                }
                // Otherwise swap and continue down the tree
                else
                {
                    T temp = arr[currentIndex];
                    arr[currentIndex] = arr[largestNodeIndex];
                    arr[largestNodeIndex] = temp;
                    currentIndex = largestNodeIndex;
                }
            }
        }

        private int getLeftNodeIndex(int nodeIndex)
        {
            int output = nodeIndex * 2;
            return nodeIndex > 2 ? output : output + 1;
        }

        private int getRightNodeIndex(int nodeIndex)
        {
            int output = nodeIndex * 2;
            return nodeIndex > 2 ? output + 1 : output + 2;
        }
    }
}
