#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    int arr[10] = {
        0,
    };

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        arr[input[i] - '0']++;
    }

    arr[9] = (arr[9] + arr[6] + 1) / 2;
    arr[6] = arr[9];

    cout << *max_element(arr, arr + 10);

    return 0;
}