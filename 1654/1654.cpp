#include <bits/stdc++.h>
using namespace std;

vector<int> lans(10001);

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int k, n;
  long long l = 1, r = -1, mid;
  cin >> k >> n;
  for (int i = 0; i < k; i++)
  {
    cin >> lans[i];
    r = max(r, (long long)lans[i]);
  }

  while (l <= r)
  {
    mid = (l + r) / 2;
    long long s = 0;
    for (int i = 0; i < k; i++)
    {
      s += (lans[i] / mid);
    }
    if (s < n)
    {
      r = mid - 1;
    }
    else
      l = mid + 1;
  }
  cout << r << '\n';

  return 0;
}