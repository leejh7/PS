#include <bits/stdc++.h>
using namespace std;
/*
 * 퀵 셀렉트란?
 * N개의 정렬되지 않은 배열에서 K번째 큰/작은 수를 찾는 알고리즘
 */

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right]; // 피봇을 끝으로 잡음 (처음 중간 끝 중 하나로 잡으면 됌)
    int i = left;
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quick_select(vector<int> &arr, int left, int right, int k)
{
    int pivot_pos = partition(arr, left, right);

    if (pivot_pos == k)
        return arr[pivot_pos];
    else if (pivot_pos < k)
    {
        return quick_select(arr, pivot_pos + 1, right, k);
    }
    else
    {
        return quick_select(arr, left, pivot_pos - 1, k);
    }
}

int main()
{
    clock_t start, end;
    start = clock();
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    int n; // arr의 요소 개수
    int k; // k번째 큰 수
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = quick_select(arr, 0, n - 1, k - 1);
    cout << res << '\n';

    end = clock();
    cout << "걸린 시간: " << (double)(end - start) / 1000 << "초\n";
    return 0;
}