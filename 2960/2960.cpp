#include <iostream>
#include <algorithm>
using namespace std;

bool arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    int n, k, cnt = 0, result;
    cin >> n >> k;

    for (int i = 2; i <= n; i++)
    {
        if (!arr[i])
        {
            for (int j = i; j <= n; j += i)
            {
                if (!arr[j])
                {
                    cnt++;
                    arr[j] = true;
                    if (cnt == k)
                    {
                        result = j;
                        cout << result;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}