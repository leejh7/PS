#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);
  long long n;
  cin >> n;
  long long mid, l = 1, r = n;
  while (l <= r)
  {
    mid = (l + r) / 2;
    if (mid * (mid + 1) / 2 > n)
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << r << '\n';
  return 0;
}