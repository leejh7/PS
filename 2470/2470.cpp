#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  int min = 2147000000;
  int result[2] = {0, 0};
  int l = 0, r = N - 1;
  while (l < r)
  {
    int sum = arr[l] + arr[r];
    if (min > abs(sum))
    {
      min = abs(sum);
      result[0] = arr[l];
      result[1] = arr[r];
    }

    if (sum < 0)
    {
      l++;
    }
    else
    {
      r--;
    }
  }
  cout << result[0] << ' ' << result[1] << '\n';
  return 0;
}