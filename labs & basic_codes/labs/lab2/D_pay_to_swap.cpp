#include <iostream>
#include <algorithm>
using namespace std;

long long merge(int arr[], int left, int mid, int right, int temp[])
{
  int i = left;
  int j = mid + 1;
  int k = left;

  long long sum = 0;

  while (i <= mid && j <= right)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      sum += 1LL * (mid - i + 1) * arr[j];
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid)
  {
    temp[k++] = arr[i++];
  }

  while (j <= right)
  {
    temp[k++] = arr[j++];
  }

  for (int p = left; p <= right; p++)
  {
    arr[p] = temp[p];
  }

  return sum;
}

long long merge_sort(int arr[], int left, int right, int temp[])
{
  if (left >= right)
  {
    return 0;
  }

  int mid = left + (right - left) / 2;

  long long left_sum = merge_sort(arr, left, mid, temp);
  long long right_sum = merge_sort(arr, mid + 1, right, temp);
  long long merge_sum = merge(arr, left, mid, right, temp);

  return left_sum + right_sum + merge_sum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int *temp = new int[n];

  long long sum = merge_sort(arr, 0, n - 1, temp);

  cout << sum << '\n';

  delete[] arr;
  delete[] temp;

  return 0;
}