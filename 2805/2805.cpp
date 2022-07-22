#include <bits/stdc++.h>
using namespace std;

int tree[1000000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, m;
  long long l = 1, r = -1, h;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> tree[i];
    r = max(r, (long long)tree[i]);
  }

  while (l <= r)
  {
    h = (l + r) / 2;
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
      s += (tree[i] - h <= 0 ? 0 : tree[i] - h);
    }
    if (s >= m)
    {
      l = h + 1;
    }
    else
    {
      r = h - 1;
    }
  }
  cout << r << '\n';

  return 0;
}