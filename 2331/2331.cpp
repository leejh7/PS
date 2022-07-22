#include <bits/stdc++.h>
using namespace std;
map<int, int> m;

int dig(int n, int p)
{
  int res = 0;
  while (n > 0)
  {
    res += pow(n % 10, p);
    n /= 10;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int a, p, prev, idx = 0, num;
  cin >> a >> p;
  m.insert({a, idx});
  prev = a;
  while (true)
  {
    idx++;
    num = dig(prev, p);
    prev = num;
    const auto [it, success] = m.insert({num, idx});
    if (!success)
      break;
  }
  auto it = m.find(num);
  cout << (it->second) - 0;
  return 0;
}