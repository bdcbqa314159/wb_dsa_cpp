#include <iostream>

using namespace std;

int Partition(int arr[], int startIndex, int endIndex) {
  int pivot = arr[startIndex];

  int middleIndex = startIndex;

  for (int i = startIndex + 1; i <= endIndex; ++i) {
    if (arr[i] < pivot) {
      ++middleIndex;

      swap(arr[i], arr[middleIndex]);
    }
  }

  swap(arr[startIndex], arr[middleIndex]);

  return middleIndex;
}

void QuickSort(int arr[], int startIndex, int endIndex) {
  if (startIndex < endIndex) {
    int pivotIndex = Partition(arr, startIndex, endIndex);

    QuickSort(arr, startIndex, pivotIndex - 1);

    QuickSort(arr, pivotIndex + 1, endIndex);
  }
}

int main() {
  cout << "Quick Sort" << endl;

  int arr[] = {25, 21, 12, 40, 37, 43, 14, 28};
  int arrSize = sizeof(arr) / sizeof(*arr);

  cout << "Initial array: ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  QuickSort(arr, 0, arrSize - 1);

  cout << "Sorted array : ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  return 0;
}