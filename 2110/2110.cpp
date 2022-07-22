#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, c;
  cin >> n >> c;
  vector<int> wifi(n);
  for (int i = 0; i < n; i++)
    cin >> wifi[i];

  sort(wifi.begin(), wifi.end());

  int l = 1, r = wifi[n - 1] - wifi[0], m;

  while (l <= r)
  {
    m = (l + r) / 2;
    int s = 1, p = wifi[0];
    for (int i = 1; i < n; i++)
    {
      if (wifi[i] - p >= m)
      {
        p = wifi[i];
        s++;
      }
    }
    if (s < c)
    {
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }
  cout << r << '\n';

  return 0;
}