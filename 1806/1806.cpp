#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, S, sum = 0, min_len = 1000001, len = 0;
  cin >> N >> S;
  for (int i = 0, j = 0; i < N; i++)
  {
    cin >> arr[i];
    sum += arr[i];
    len++;
    while (j <= i && sum >= S)
    {
      min_len = min_len > len ? len : min_len;
      sum -= arr[j++];
      len--;
    }
  }
  if (min_len == 1000001)
    min_len = 0;
  cout << min_len << '\n';
  return 0;
}