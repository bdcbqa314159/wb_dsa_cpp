#include <iostream>

using namespace std;

void Merge(int arr[], int startIndex, int middleIndex, int endIndex) {
  int totalElements = endIndex - startIndex + 1;

  int* tempArray = new int[totalElements];

  int leftIndex = startIndex;

  int rightIndex = middleIndex + 1;

  int mergedIndex = 0;

  while (leftIndex <= middleIndex && rightIndex <= endIndex) {
    if (arr[leftIndex] <= arr[rightIndex]) {
      tempArray[mergedIndex] = arr[leftIndex];

      ++leftIndex;
    } else {
      tempArray[mergedIndex] = arr[rightIndex];
      ++rightIndex;
    }

    ++mergedIndex;
  }

  while (leftIndex <= middleIndex) {
    tempArray[mergedIndex] = arr[leftIndex];

    ++leftIndex;

    ++mergedIndex;
  }

  while (rightIndex <= endIndex) {
    tempArray[mergedIndex] = arr[rightIndex];

    ++rightIndex;

    ++mergedIndex;
  }

  for (int i = 0; i < totalElements; ++i) {
    arr[startIndex + i] = tempArray[i];
  }

  delete[] tempArray;

  return;
}

void MergeSort(int arr[], int startIndex, int endIndex) {
  if (startIndex < endIndex) {
    int middleIndex = (startIndex + endIndex) / 2;

    MergeSort(arr, startIndex, middleIndex);

    MergeSort(arr, middleIndex + 1, endIndex);

    Merge(arr, startIndex, middleIndex, endIndex);
  }

  return;
}

int main() {
  cout << "Merge Sort" << endl;

  int arr[] = {7, 1, 5, 9, 3, 6, 8, 2};
  int arrSize = sizeof(arr) / sizeof(*arr);

  cout << "Initial array: ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  MergeSort(arr, 0, arrSize - 1);

  cout << "Sorted array : ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  return 0;
}