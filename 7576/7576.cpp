#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};

int bfs(queue<pair<int, int>> &q, int &cnt, int m, int n)
{
  int res = -1;
  while (!q.empty())
  {
    int s = q.size();
    res++;
    for (int i = 0; i < s; i++)
    {
      int x_pos = q.front().first;
      int y_pos = q.front().second;
      q.pop();
      for (int j = 0; j < 4; j++)
      {
        int xx = x_pos + x[j];
        int yy = y_pos + y[j];
        if (0 < xx && xx <= m && 0 < yy && yy <= n)
        {
          if (arr[yy][xx] == 0)
          {
            arr[yy][xx] = 1;
            q.push({xx, yy});
            cnt++;
          }
        }
      }
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int m, n, cnt = 0, total_cnt;
  queue<pair<int, int>> q;
  cin >> m >> n;
  total_cnt = m * n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 1)
      {
        q.push({j, i});
        cnt++;
      }
      else if (arr[i][j] == -1)
        total_cnt--;
    }
  }

  if (cnt == total_cnt)
  {
    cout << 0 << '\n';
  }
  else
  {
    int res = bfs(q, cnt, m, n);
    if (cnt == total_cnt)
      cout << res << '\n';
    else
      cout << -1 << '\n';
  }

  return 0;
}