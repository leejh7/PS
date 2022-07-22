#include <bits/stdc++.h>
using namespace std;

vector<int> graph[20001];
int check[20001];

void init(int v)
{
  for (int i = 1; i <= v; i++)
  {
    graph[i].clear();
    check[i] = 0;
  }
}

bool dfs(int start, int group)
{
  check[start] = group;

  for (int i = 0; i < graph[start].size(); i++)
  {
    int next = graph[start][i];
    if (check[next] == 0)
    {
      if (!dfs(graph[start][i], -group))
        return false;
    }
    else
    {
      if (check[start] == check[next])
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int k;
  cin >> k;
  while (k--)
  {
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
      int u, t;
      cin >> u >> t;
      graph[u].push_back(t);
      graph[t].push_back(u);
    }
    bool ans = true;
    for (int i = 1; i <= v; i++)
    {
      if (check[i] == 0)
      {
        ans = dfs(i, 1);
        if (!ans)
          break;
      }
    }
    cout << (ans ? "YES\n" : "NO\n");
    init(v);
  }

  return 0;
}