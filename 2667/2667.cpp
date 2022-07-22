#include <bits/stdc++.h>
using namespace std;
int sum;
int m[30][30];
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};
vector<int> result;

void dfs(int cur_x, int cur_y)
{
  m[cur_y][cur_x] = 0;
  sum++;
  for (int i = 0; i < 4; i++)
  {
    int xx = cur_x + x[i];
    int yy = cur_y + y[i];
    if (m[yy][xx])
    {
      dfs(xx, yy);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  string num;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> num;
    for (int j = 1; j <= n; j++)
    {
      m[i][j] = num[j - 1] - '0';
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (m[i][j] != 0)
      {
        sum = 0;
        dfs(j, i);
        result.push_back(sum);
      }
    }
  }
  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << '\n';
  return 0;
}