#include <cmath>
#include <iostream>

using namespace std;

int LinearSearch(int arr[], int startIndex, int endIndex, int val) {
  for (int i = startIndex; i < endIndex; ++i) {
    if (arr[i] == val) {
      return i;
    }
  }

  return -1;
}

int JumpSearch(int arr[], int arrSize, int val) {
  if (arrSize <= 0) {
    return -1;
  }

  int step = sqrt(arrSize);

  int blockIndex = 0;

  while (blockIndex < arrSize && arr[blockIndex] < val) {
    blockIndex += step;
  }

  return LinearSearch(arr, blockIndex - step, min(blockIndex, arrSize), val);
}

int main() {
  cout << "Jump Search" << endl;

  int arr[] = {8, 15, 23, 28, 32, 39, 42, 44, 47, 48};
  int arrSize = sizeof(arr) / sizeof(*arr);

  int searchedValue = 39;

  int i = JumpSearch(arr, arrSize, searchedValue);

  if (i != -1) {
    cout << searchedValue << " is found in index ";
    cout << i << endl;
  } else {
    cout << "Could not find value " << searchedValue;
    cout << endl;
  }

  return 0;
}