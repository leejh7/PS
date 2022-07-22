#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool check[1001];

void dfs(int start)
{
  check[start] = true;
  for (int i = 0; i < graph[start].size(); i++)
  {
    int next = graph[start][i];
    if (!check[next])
    {
      dfs(next);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int t;
  cin >> t;
  while (t--)
  {
    int n, v, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      graph[i].clear();
      check[i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> v;
      graph[i].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
      if (!check[i])
      {
        res++;
        dfs(i);
      }
    }
    cout << res << '\n';
  }

  return 0;
}