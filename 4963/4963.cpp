#include <bits/stdc++.h>
using namespace std;

int x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

void dfs(int cur_x, int cur_y, vector<vector<int>> &m)
{
  m[cur_y][cur_x] = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      int xx = cur_x + x[i];
      int yy = cur_y + y[i];
      if (m[yy][xx])
        dfs(xx, yy, m);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int w, h, input;
  while (true)
  {
    int res = 0;
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    vector<vector<int>> m(h + 2, vector<int>(w + 2));
    for (int i = 1; i <= h; i++)
    {
      for (int j = 1; j <= w; j++)
      {
        cin >> input;
        m[i][j] = input;
      }
    }

    for (int i = 1; i <= h; i++)
    {
      for (int j = 1; j <= w; j++)
      {
        if (m[i][j])
        {
          dfs(j, i, m);
          res++;
        }
      }
    }
    cout << res << '\n';
  }

  return 0;
}