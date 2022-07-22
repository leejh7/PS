#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool np_arr[4000001];
vector<int> p_arr;

void init(int n)
{
  np_arr[1] = true;
  for (int i = 2; i <= n; i++)
  {
    if (!np_arr[i])
    {
      p_arr.push_back(i);
      for (int j = i * 2; j <= n; j += i)
      {
        np_arr[j] = true;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

  int N, sum = 0, cnt = 0;
  cin >> N;
  init(N);

  for (int i = 0, j = 0; i < p_arr.size(); i++)
  {
    sum += p_arr[i];
    while (j <= i && sum > N)
    {
      sum -= p_arr[j++];
    }
    if (sum == N)
    {
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}