#include <iostream>
using namespace std;

// 找第一个 >= tar 的位置
int lowerBound(int arr[], int left, int right, long long tar)
{

    while (left <= right)
    {

        int mid = left + (right - left) / 2;

        if (arr[mid] >= tar)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

// 找第一个 > tar 的位置
int upperBound(int arr[], int left, int right, long long tar)
{

    while (left <= right)
    {

        int mid = left + (right - left) / 2;

        if (arr[mid] > tar)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

// 统计 tar 在 arr[left...right] 中出现多少次
int binarySearch(int arr[], int left, int right, long long tar)
{

    if (left > right)
    {
        return 0;
    }

    int lower = lowerBound(arr, left, right, tar);
    int upper = upperBound(arr, left, right, tar);

    return upper - lower;
}

void merge(int arr[], int left, int mid, int right, int temp[])
{

    int i = left;
    int j = mid + 1;
    int k = left;

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

    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

void merge_sort(int arr[], int left, int right, int temp[])
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

    int n;
    long long m;

    cin >> n >> m;

    int *arr = new int[n];
    int *temp = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // merge sort
    merge_sort(arr, 0, n - 1, temp);

    long long num = 0;

    // 枚举 i < j
    for (int i = 0; i < n - 2; i++)
    {

        for (int j = i + 1; j < n - 1; j++)
        {

            long long tar = m - arr[i] - arr[j];

            // 只在 j 后面找 k
            num += binarySearch(arr, j + 1, n - 1, tar);
        }
    }

    cout << num << '\n';

    delete[] arr;
    delete[] temp;

    return 0;
}