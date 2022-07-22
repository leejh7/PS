#include <bits/stdc++.h>
using namespace std;

int arr[500001], sorted[500001];

long long cnt = 0;
void merge(int left, int right, int mid)
{
  int l = left, r = mid + 1, k = left;
  while (l <= mid && r <= right)
  {
    if (arr[l] <= arr[r])
      sorted[k++] = arr[l++];
    else
    {
      cnt += mid - l + 1;
      sorted[k++] = arr[r++];
    }
  }
  while (l <= mid)
    sorted[k++] = arr[l++];
  while (r <= right)
    sorted[k++] = arr[r++];
  for (int i = left; i <= right; i++)
  {
    arr[i] = sorted[i];
  }
}

void merge_sort(int left, int right)
{
  if (left == right)
    return;
  int mid = (left + right) / 2;
  merge_sort(left, mid);
  merge_sort(mid + 1, right);
  merge(left, right, mid);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  merge_sort(0, n - 1);
  cout << cnt << '\n';

  return 0;
}