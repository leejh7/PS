#include <bits/stdc++.h>
using namespace std;

int in_degree[100];
bool visited[100];
vector<int> graph[100];
queue<int> q;

void sol(int n)
{
  vector<int> result;
  for (int i = 0; i < n; i++)
  {
    if (visited[i])
      continue;
    if (in_degree[i] == 0)
    {
      result.push_back(i);
      q.push(i);
      visited[i] = true;
    }
  }

  while (!q.empty())
  {
    int x = q.front();
    q.pop();

    for (int i = 0; i < graph[x].size(); i++)
    {
      int next = graph[x][i];
      in_degree[next]--;
      if (!visited[next] && in_degree[next] == 0)
      {
        result.push_back(next);
        q.push(next);
        visited[next] = true;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << result[i] << ' ';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, m, u, v;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> u >> v;
    graph[u].push_back(v);
    in_degree[v]++;
  }
  sol(n);

  return 0;
}