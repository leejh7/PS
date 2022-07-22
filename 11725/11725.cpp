#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100001];
int result[100001];
bool visited[100001];

void bfs()
{
  queue<int> q;
  q.push(1);
  visited[1] = true;

  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int i = 0; i < tree[x].size(); i++)
    {
      int child = tree[x][i];
      if (!visited[child])
      {
        result[child] = x;
        q.push(child);
        visited[child] = true;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, a, b;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  bfs();
  for (int i = 2; i <= n; i++)
    cout << result[i] << '\n';

  return 0;
}