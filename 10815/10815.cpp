#include <bits/stdc++.h>
using namespace std;

bool card[20000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int n, m, a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    card[a + 10000000] = true;
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> a;
    cout << card[a + 10000000] << ' ';
  }

  return 0;
}