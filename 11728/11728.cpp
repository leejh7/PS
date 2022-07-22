#include <bits/stdc++.h>
using namespace std;
vector<int> result, a, b;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int sa, sb, input, pa = 0, pb = 0;
  cin >> sa >> sb;
  for (int i = 0; i < sa; i++)
  {
    cin >> input;
    a.push_back(input);
  }
  for (int i = 0; i < sb; i++)
  {
    cin >> input;
    b.push_back(input);
  }

  while (pa < sa && pb < sb)
  {
    if (a[pa] < b[pb])
    {
      result.push_back(a[pa++]);
    }
    else
    {
      result.push_back(b[pb++]);
    }
  }

  while (pa < sa)
  {
    result.push_back(a[pa++]);
  }

  while (pb < sb)
  {
    result.push_back(b[pb++]);
  }

  for (auto i : result)
  {
    cout << i << ' ';
  }

  cout << '\n';
  return 0;
}