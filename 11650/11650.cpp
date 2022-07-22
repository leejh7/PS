#include <bits/stdc++.h>
using namespace std;

typedef struct _ordinate
{
  int x, y;
  bool operator<(const _ordinate &o) const
  {
    if (x == o.x)
    {
      return y < o.y;
    }
    else
    {
      return x < o.x;
    }
    return false;
  }
} ordinate;

bool comp(ordinate o1, ordinate o2)
{
  if (o1.x == o2.x)
  {
    return o1.y < o2.y;
  }
  else
  {
    return o1.x < o2.x;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<ordinate> ord(n);

  for (int i = 0; i < n; i++)
  {
    cin >> ord[i].x >> ord[i].y;
  }
  sort(ord.begin(), ord.end());

  for (int i = 0; i < n; i++)
  {
    cout << ord[i].x << ' ' << ord[i].y << '\n';
  }
  return 0;
}