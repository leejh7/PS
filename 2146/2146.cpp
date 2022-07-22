#include <bits/stdc++.h>
using namespace std;

int n;
int arr[105][105];
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};
bool visited[101][101];

class Land
{
public:
  int x, y, cnt;
  Land(int x, int y, int cnt)
  {
    this->x = x;
    this->y = y;
    this->cnt = cnt;
  }
};

void dis_dfs(int cur_x, int cur_y, int l)
{
  arr[cur_y][cur_x] = l;
  for (int i = 0; i < 4; i++)
  {
    int xx = cur_x + x[i];
    int yy = cur_y + y[i];
    if (arr[yy][xx] == 1)
    {
      dis_dfs(xx, yy, l);
    }
  }
}

int sol_bfs(int cur_x, int cur_y, int l)
{
  queue<Land> q;
  q.push(Land(cur_x, cur_y, 0));
  while (!q.empty())
  {
    int x_pos = q.front().x;
    int y_pos = q.front().y;
    int cnt = q.front().cnt;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int xx = x_pos + x[i];
      int yy = y_pos + y[i];
      if (0 < xx && xx <= n && 0 < yy && yy <= n)
      {
        int val = arr[yy][xx];
        if (val == 0 && !visited[yy][xx]) // 방문하지 않은 바다
        {
          visited[yy][xx] = true;
          q.push(Land(xx, yy, cnt + 1));
        }
        if (val != 0 && val != l)
        {
          return cnt;
        }
      }
    }
  }
  return INT_MAX;
}

void distinguish()
{
  int l = 2;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == 1)
      {
        dis_dfs(j, i, l);
        l++;
      }
    }
  }
}

void solution()
{
  int res = INT_MAX;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] != 0)
      {
        memset(visited, false, sizeof(visited));
        res = min(res, sol_bfs(j, i, arr[i][j]));
      }
    }
  }
  cout << res;
}

void print()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cout << arr[i][j] << ' ';
    cout << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }

  distinguish();

  print();
  solution();

  return 0;
}