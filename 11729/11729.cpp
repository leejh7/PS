#include <bits/stdc++.h>
using namespace std;

int k;
vector<pair<int, int>> res;
void hanoi(int start, int to, int end, int n)
{
  if (n == 0)
    return;
  k++;
  hanoi(start, end, to, n - 1);
  res.push_back({start, end});
  hanoi(to, start, end, n - 1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  cin >> n;
  hanoi(1, 2, 3, n);
  cout << k << '\n';
  for (int i = 0; i < k; i++)
  {
    cout << res[i].first << ' ' << res[i].second << '\n';
  }
  return 0;
}