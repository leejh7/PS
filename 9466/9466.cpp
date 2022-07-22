#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int res;
int graph[MAXN];
bool ch[MAXN], visited[MAXN];

void dfs(int start)
{
  visited[start] = true;
  int next = graph[start];

  if (!visited[next])
    dfs(next);
  else if (!ch[next])
  {
    int i = next;
    while (true)
    {
      res++;
      if (i == start)
        break;
      i = graph[i];
    }
  }

  ch[start] = true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int t, n, v;
  cin >> t;
  while (t--)
  {
    memset(visited, false, sizeof(visited));
    memset(ch, false, sizeof(ch));
    res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
      cin >> v;
      graph[i] = v;
    }

    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
        dfs(i);
    }

    cout << n - res << '\n';
  }

  return 0;
}