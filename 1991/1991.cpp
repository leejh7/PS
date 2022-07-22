#include <bits/stdc++.h>
using namespace std;

pair<char, char> tree[26];

void pre(int idx)
{
  int left = tree[idx].first;
  int right = tree[idx].second;
  printf("%c", idx + 'A');
  if (left > 0)
    pre(left);
  if (right > 0)
    pre(right);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  char a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b >> c;
    tree[a - 'A'].first = b - 'A';
    tree[a - 'A'].second = c - 'A';
  }

  pre(0);

  return 0;
}