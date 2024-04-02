#include <bits/stdc++.h>
using namespace std;
int n, a[1028];
vector<int> tree[11];

void go(int start, int end, int level) {
    if (start == end) {
        tree[level].push_back(a[start]);
        return;
    }
    int mid = (start + end) / 2;
    tree[level].push_back(a[mid]);
    go(start, mid - 1, level + 1);
    go(mid + 1, end, level + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < (int)pow(2, n) - 1; i++) {
        cin >> a[i];
    }
    go(0, (int)pow(2, n) - 2, 0);

    for (int i = 0; i < n; i++) {
        for (int node : tree[i]) {
            cout << node << " ";
        }
        cout << '\n';
    }
    return 0;
}