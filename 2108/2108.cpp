#include <bits/stdc++.h>
using namespace std;

vector<int> cnt(8001, 0);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, total = 0, freq = -1; // 최빈도수
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    total += arr[i];
    ++cnt[arr[i] + 4000];
    freq = freq < cnt[arr[i] + 4000] ? cnt[arr[i] + 4000] : freq;
  }

  sort(arr.begin(), arr.end());

  int avg = round((float)total / n);

  vector<int> res;
  for (int i = 0; i < 8001; i++)
  {
    if (freq == cnt[i])
      res.push_back(i - 4000);
  }

  cout << avg << '\n';
  cout << arr[n / 2] << '\n';
  cout << (res.size() > 1 ? res[1] : res[0]) << '\n';
  cout << arr.back() - arr.front();

  return 0;
}