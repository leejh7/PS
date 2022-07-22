#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> graph[1001];
bool vis[1001];

void dfs(int start)
{
  vis[start] = true;
  cout << start << ' ';

  for (int i = 0; i < graph[start].size(); i++)
  {
    if (!vis[graph[start][i]])
    {
      dfs(graph[start][i]);
    }
  }
}

void bfs(int start)
{
  memset(vis, false, sizeof(vis));
  queue<int> q;
  q.push(start);
  vis[start] = true;

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    cout << x << ' ';
    for (int i = 0; i < graph[x].size(); i++)
    {
      if (!vis[graph[x][i]])
      {
        q.push(graph[x][i]);
        vis[graph[x][i]] = true;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  cin >> n >> m >> v;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(v);
  cout << '\n';
  bfs(v);

  return 0;
}