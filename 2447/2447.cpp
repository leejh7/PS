#include <bits/stdc++.h>
using namespace std;

void star(int i, int j, int n)
{
  int x = n / 3;
  if (x == 0)
    cout << '*';
  else
  {
    if (i / x % 3 == 1 && j / x % 3 == 1)
    {
      cout << ' ';
    }
    else
    {
      star(i, j, n / 3);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      star(i, j, n);
    }
    cout << '\n';
  }

  return 0;
}