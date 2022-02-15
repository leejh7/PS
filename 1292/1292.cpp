#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    int idx = 1, num = 1;
    while (idx <= 1000)
    {
        for (int i = idx; i < idx + num && i <= 1000; i++)
            arr[i] = num;
        idx += num;
        num++;
    }

    int a, b, result = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        result += arr[i];
    }
    cout << result;
    return 0;
}