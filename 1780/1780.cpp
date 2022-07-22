#include <bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int result[3];

bool same(int sx, int sy, int n)
{
  int p = arr[sy][sx];
  for (int i = sy; i < sy + n; i++)
  {
    for (int j = sx; j < sx + n; j++)
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
    result[arr[y][x] + 1]++;
    return;
  }
  n /= 3;
  if (n < 1)
    return;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      sol(x + i * n, y + j * n, n);
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
      cin >> arr[i][j];
    }
  }

  sol(0, 0, n);
  for (int i = 0; i < 3; i++)
    cout << result[i] << '\n';

  return 0;
}