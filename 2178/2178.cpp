#include <bits/stdc++.h>
using namespace std;

class Miro
{
public:
  int x, y, cnt;
  Miro(int x, int y, int cnt)
  {
    this->x = x;
    this->y = y;
    this->cnt = cnt;
  }
};

int n,
    m;
int arr[101][101];
bool visited[101][101];
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};

int bfs()
{
  queue<Miro> q;
  q.push(Miro(1, 1, 1));

  while (!q.empty())
  {
    int cur_x = q.front().x;
    int cur_y = q.front().y;
    int cur_cnt = q.front().cnt;
    q.pop();

    if (cur_x == m && cur_y == n)
      return cur_cnt;

    for (int i = 0; i < 4; i++)
    {
      int xx = cur_x + x[i];
      int yy = cur_y + y[i];
      if (0 < xx && xx <= m && 0 < yy && yy <= n)
      {
        if (!visited[yy][xx] && arr[yy][xx] == 1)
        {
          q.push(Miro(xx, yy, cur_cnt + 1));
          visited[yy][xx] = true;
        }
      }
    }
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  string input;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> input;
    for (int j = 1; j <= m; j++)
    {
      arr[i][j] = input[j - 1] - '0';
    }
  }

  cout << bfs();
  return 0;
}