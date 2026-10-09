#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct tead
{
  int a;
  int b;
  bool x;
};

// 判断 p 是否应该排在 q 前面
bool before(tead p, tead q)
{
  // true 组全部放在 false 组前面
  if (p.x != q.x)
  {
    return p.x;
  }

  if (p.x == true)
  {
    return p.a <= q.a;
  }
  return p.b >= q.b;
}

void merge(vector<tead> &arr, int left, int mid, int right, vector<tead> &temp)
{
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right)
  {
    if (before(arr[i], arr[j]))
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

  for (int p = left; p <= right; p++)
  {
    arr[p] = temp[p];
  }
}

void merge_sort(vector<tead> &arr, int left, int right, vector<tead> &temp)
{
  if (left >= right)
  {
    return;
  }

  int mid = left + (right - left) / 2;

  merge_sort(arr, left, mid, temp);
  merge_sort(arr, mid + 1, right, temp);

  merge(arr, left, mid, right, temp);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--)
  {
    int n;
    cin >> n;

    vector<tead> arr(n);
    vector<tead> temp(n);

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i].a >> arr[i].b;

      if (arr[i].a <= arr[i].b)
      {
        arr[i].x = true;
      }
      else
      {
        arr[i].x = false;
      }
    }

    // 排序
    merge_sort(arr, 0, n - 1, temp);

    long long power = 0;

    // 当前最右边可以用于消除 blue 的 red 数量
    long long red = 0;

    for (int i = 0; i < n; i++)
    {
      // 当前 red 可以消掉多少个当前串最左边的 blue
      long long disappear = min(red, (long long)arr[i].a);

      power += disappear;

      // 消掉 disappear 对
      red -= disappear;

      // 当前串产生 b 个新的 red
      red += arr[i].b;
    }

    cout << power << '\n';
  }

  return 0;
}