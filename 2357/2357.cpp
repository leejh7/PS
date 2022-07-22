#include <bits/stdc++.h>
using namespace std;

struct Data
{
  int min;
  int max;
  Data()
  {
    min = INT32_MAX;
    max = INT32_MIN;
  }
  Data(int a, int b)
  {
    min = a;
    max = b;
  }
};

int n, m;
vector<Data> tree(400001);

void update(int start, int end, int idx, int val, int node)
{
  if (start > idx || end < idx)
    return;
  tree[node].min = min(tree[node].min, val);
  tree[node].max = max(tree[node].max, val);
  if (start == end)
    return;
  int mid = (start + end) / 2;
  update(start, mid, idx, val, node * 2);
  update(mid + 1, end, idx, val, node * 2 + 1);
}

Data find_f(int start, int end, int left, int right, int node)
{
  if (left > end || right < start)
    return Data(INT32_MAX, INT32_MIN);
  if (left <= start && end <= right)
    return tree[node];
  int mid = (start + end) / 2;
  Data leftNode = find_f(start, mid, left, right, node * 2);
  Data rightNode = find_f(mid + 1, end, left, right, node * 2 + 1);
  int min_val = min(leftNode.min, rightNode.min);
  int max_val = max(leftNode.max, rightNode.max);
  return Data(min_val, max_val);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    int input;
    cin >> input;
    update(1, n, i, input, 1);
  }
  while (m--)
  {
    int left, right;
    cin >> left >> right;
    Data res = find_f(1, n, left, right, 1);
    cout << res.min << ' ' << res.max << '\n';
  }
  return 0;
}