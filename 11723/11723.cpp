#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool arr[21];

void add(int idx)
{
    arr[idx] = true;
}

void remove(int idx)
{
    arr[idx] = false;
}

void toggle(int idx)
{
    arr[idx] = arr[idx] ? false : true;
}

void all()
{
    for (int i = 1; i <= 20; i++)
    {
        arr[i] = true;
    }
}

void empty()
{
    for (int i = 1; i <= 20; i++)
    {
        arr[i] = false;
    }
}

void check(int idx)
{
    if (arr[idx])
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string func;
        int idx;
        cin >> func;
        if (func == "add")
        {
            cin >> idx;
            add(idx);
        }
        else if (func == "remove")
        {
            cin >> idx;
            remove(idx);
        }
        else if (func == "toggle")
        {
            cin >> idx;
            toggle(idx);
        }
        else if (func == "check")
        {
            cin >> idx;
            check(idx);
        }
        else if (func == "all")
        {
            all();
        }
        else
        {
            empty();
        }
    }

    return 0;
}