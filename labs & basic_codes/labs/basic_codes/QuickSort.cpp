#include <iostream>
#include <algorithm>
using namespace std;
void quickSort(int arr[], int low, int high)
{
  if (low >= high)
    return;
  int pivot = partition(arr, low, high);

  quickSort(arr, low, pivot - 1);
  quickSort(arr, pivot + 1, high);
}
int partition(int A[], int low, int high)
{
  int pivot = A[low];
  while (low < high)
  {
    while (low < high && A[high] >= pivot)
      high--; // 找到小于pivot的放到左边

    A[low] = A[high];

    // 找到大于pivot的放到右边
    while (low < high && A[low] <= pivot)

      low++;

    A[high] = A[low];
  }

  A[low] = pivot; // 把pivot 填回最后的坑

  return low;
}
