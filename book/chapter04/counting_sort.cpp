#include <iostream>

using namespace std;

void CountingSort(int arr[], int arrSize) {
  int counterSize = 10;
  int* counterArray = new int[counterSize];

  for (int i = 0; i < arrSize; ++i) {
    ++counterArray[arr[i]];
  }

  int arrCounter = 0;

  for (int i = 0; i < counterSize; ++i) {
    while (counterArray[i] > 0) {
      arr[arrCounter++] = i;

      --counterArray[i];
    }
  }
}

int main() {
  cout << "Counting Sort" << endl;

  int arr[] = {9, 6, 5, 6, 1, 7, 2, 4, 3, 5, 7, 7, 9, 6};
  int arrSize = sizeof(arr) / sizeof(*arr);

  cout << "Initial array: ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  CountingSort(arr, arrSize);

  cout << "Sorted array : ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  return 0;
}