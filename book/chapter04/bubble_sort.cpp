#include <iostream>

using namespace std;

void BubbleSort(int arr[], int arrSize) {
  bool isSwapped{false};

  int unsortedElements = arrSize;

  do {
    isSwapped = false;
    for (int i = 0; i < unsortedElements - 1; ++i) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        isSwapped = true;
      }
    }
    --unsortedElements;
  } while (isSwapped);
}

int main() {
  cout << "Bubble Sort" << endl;

  int arr[] = {43, 21, 26, 38, 17, 30};
  int arrSize = sizeof(arr) / sizeof(*arr);

  cout << "Initial array: ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  BubbleSort(arr, arrSize);

  cout << "Sorted array : ";
  for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
  cout << endl;

  return 0;
}