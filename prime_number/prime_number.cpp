#include <bits/stdc++.h>
#define END 100001
using namespace std;
/*
 * 1 ~ 100000 까지의 소수 찾기
 */

vector<bool> prime(END, true);
void init()
{
  prime[0] = prime[1] = false;

  for (long long i = 2; i <= sqrt(END); i++)
  {
    if (prime[i])
    {
      for (long long j = i * i; j <= END; j += i)
      {
        prime[j] = false;
      }
    }
  }
}
int main()
{
  init();

  for (int i = 1; i <= END; i++)
  {
    if (prime[i])
      cout << i << ' ';
  }

  return 0;
}