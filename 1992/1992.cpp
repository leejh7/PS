#include <bits/stdc++.h>
using namespace std;

int arr[70][70];

bool same(int x, int y, int n)
{
  int p = arr[y][x];
  for (int i = y; i < y + n; i++)
  {
    for (int j = x; j < x + n; j++)
    {
      if (arr[i][j] != p)
        return false;
    }
  }
  return true;
}

void sol(int x, int y, int n)
{
  if (same(x, y, n))
  {
    cout << arr[y][x];
    return;
  }
  n /= 2;
  if (n < 1)
    return;
  cout << '(';
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      sol(x + j * n, y + i * n, n);
    }
  }
  cout << ')';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  string input;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    for (int j = 0; j < n; j++)
      arr[i][j] = input[j] - '0';
  }
  sol(0, 0, n);

  return 0;
}