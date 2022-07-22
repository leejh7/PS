#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int sum = 0, cnt = 0;
  for (int l = 0, r = 0; r < n; r++)
  {
    sum += arr[r];
    while (sum > m && l <= r)
    {
      sum -= arr[l];
      l++;
    }
    if (sum == m)
      cnt++;
  }

  cout << cnt << '\n';
  return 0;
}