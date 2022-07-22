#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int arr[5000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int N, L;
  cin >> N >> L;

  deque<pair<int, int>> dq;
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++)
  {
    if (!dq.empty() && dq.front().first == i)
    {
      dq.pop_front();
    }
    while (!dq.empty() && dq.back().second > arr[i])
    {
      if (dq.back().second > arr[i])
      {
        dq.pop_back();
      }
    }
    dq.push_back({i + L, arr[i]});
    cout << dq.front().second << ' ';
  }
  cout << '\n';

  return 0;
}