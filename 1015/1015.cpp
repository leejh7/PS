#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int idx;    // 인덱스
    int val;    // 값
    int ord;    // 순서
} Node;

bool compVal(Node a, Node b) {
    if(a.val != b.val) return a.val < b.val;
    return a.idx < b.idx;   // val이 같은 경우 인덱스 순으로 정렬
}

bool compIdx(Node a, Node b) {
    return a.idx < b.idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("/Volumes/Programming/C:C++/input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<Node> v;
    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        v.push_back({i, input, 0});
    }
    sort(v.begin(), v.end(), compVal);
    for(int i=0; i<n; i++) {
        v[i].ord = i;
    }
    sort(v.begin(), v.end(), compIdx);
    for(int i=0; i<n; i++) {
        cout << v[i].ord;
        if(i!=n-1) cout << " ";
    }

    return 0;
}