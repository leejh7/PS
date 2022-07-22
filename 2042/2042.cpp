#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;
vector<long long> arr;

long long make_tree(int node, int start, int end)
{
  if (start == end)
  {
    return tree[node] = arr[start];
  }
  else
  {
    int mid = (start + end) / 2;
    return tree[node] = make_tree(node * 2, start, mid) + make_tree(node * 2 + 1, mid + 1, end);
  }
}

long long sum(int start, int end, int node, int left, int right)
{
  if (left > end || right < start)
    return 0;
  if (left <= start && end <= right)
    return tree[node];
  int mid = (start + end) / 2;
  return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int target_idx, long long update_val, int start, int end, int node)
{
  if (target_idx < start || target_idx > end)
    return;
  tree[node] += update_val;
  if (start == end)
  {
    return;
  }
  int mid = (start + end) / 2;
  update(target_idx, update_val, start, mid, node * 2);
  update(target_idx, update_val, mid + 1, end, node * 2 + 1);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, m, k;
  cin >> n >> m >> k;
  tree.resize(n * 4 + 1);
  arr.resize(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  make_tree(1, 0, n - 1);
  for (int i = 0; i < m + k; i++)
  {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    if (a == 1)
    {
      update(b - 1, c - arr[b - 1], 0, n - 1, 1);
      arr[b - 1] = c;
    }
    else
    {
      cout << sum(0, n - 1, 1, b - 1, c - 1) << '\n';
    }
  }

  return 0;
}