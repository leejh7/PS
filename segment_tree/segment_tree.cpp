#include <bits/stdc++.h>
using namespace std;

/*
 * 세그먼트 트리란? 연속된 부분을 구하기 위한 알고리즘
 * 선형적으로 구하는 경우: O(N)
 * 세그먼트 트리 이용하는 경우: O(logN)
 *
 * 트리는 배열을 이용할 것 (트리 자료구조를 사용해도 됨 편의상 배열 사용)
 */

int n = 12;                  // 원소의 개수
vector<int> tree(n * 4 + 1); // 세그먼트 트리: 크기는 N*4로 만든다
vector<int> arr(n);          // 입력 받을 배열

int make_tree(int node, int start, int end)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        return tree[node] = make_tree(node * 2, start, mid) + make_tree(node * 2 + 1, mid + 1, end);
    }
}

int sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int update(int target_idx, int update_val, int start, int end, int node)
{
    int mid = (start + end) / 2;
    if (start == end && mid == target_idx)
    {
        int dif = update_val - tree[node];
        tree[node] = update_val;
        return dif;
    }
    else
    {
        int dif = 0;
        if (target_idx <= mid)
        {
            dif = update(target_idx, update_val, start, mid, node * 2);
            tree[node] += dif;
            return dif;
        }
        else
        {
            dif = update(target_idx, update_val, mid + 1, end, node * 2 + 1);
            tree[node] += dif;
            return dif;
        }
    }
}

void print_tree(int start, int end)
{
    if (start >= end)
    {
        if (tree[start] != 0)
            cout << tree[start] << ' ';
    }
    else
    {
        if (tree[start] != 0)
            cout << tree[start] << ' ';
        print_tree(start * 2, end);
        print_tree(start * 2 + 1, end);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int total = make_tree(1, 0, n - 1); // node의 시작은 1부터
    print_tree(1, tree.size());
    cout << '\n';
    int sub_sum = sum(0, n - 1, 1, 4, 8); // 4~8번째 원소들의 합
    cout << sub_sum << '\n';
    update(7, 6, 0, n - 1, 1);
    print_tree(1, tree.size());
    cout << '\n';
    return 0;
}