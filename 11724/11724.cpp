#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool vis[1001];

void dfs(int start)
{
  vis[start] = true;

  for (int i = 0; i < graph[start].size(); i++)
  {
    if (!vis[graph[start][i]])
    {
      dfs(graph[start][i]);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, m, res = 0;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      res++;
      dfs(i);
    }
  }
  cout << res;
  return 0;
}