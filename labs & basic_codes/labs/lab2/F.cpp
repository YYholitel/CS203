#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void merge(long long arr[], long long left, long long mid, long long right, long long temp[])
{
  int i = left;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= right)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
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
  for (int i = 0; i < k; i++)
  {
    arr[left + i] = temp[i];
  }
}
void merge_sort(long long arr[], long long left, long long right, long long temp[])
{
  if (left >= right)
    return;
  long long mid = left + (right - left) / 2;
  merge_sort(arr, left, mid, temp);
  merge_sort(arr, mid + 1, right, temp);
  merge(arr, left, mid, right, temp);
}
struct tead
{
  int a;
  int b;
  bool x;
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    int n;
    cin >> n;

    vector<tead> arr(n);
    vector<tead> temp(n);
    for (int j = 0; j < n; j++)
    {
      int a, b;
      cin >> a >> b;
      arr[j] = {a, b, false};
      if (arr[j].a <= arr[j].b)
      {
        arr[j].x = true;
      } // 如果左侧小于右侧，那么就是true
    }
    // 对于每个true的 ，我们使用merge sort  按照a 升序排序
    // 对false ,b降序排序
  }
}