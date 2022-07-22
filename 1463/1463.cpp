#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<int> memo(n + 1);
  memo[2] = 1;
  memo[3] = 1;

  for (int i = 4; i <= n; i++)
  {
    memo[i] = memo[i - 1] + 1;
    if (i % 2 == 0)
    {
      memo[i] = memo[i] > memo[i / 2] + 1 ? memo[i / 2] + 1 : memo[i];
    }
    if (i % 3 == 0)
    {
      memo[i] = memo[i] > memo[i / 3] + 1 ? memo[i / 3] + 1 : memo[i];
    }
  }
  cout << memo[n] << '\n';

  return 0;
}