#include <bits/stdc++.h>
using namespace std;
int k, a[1028];
vector<int> v[14];

void recur(int s, int e, int level) {
    if (s > e) return;
    if (s == e) {
        v[level].push_back(a[s]);
        return;
    }
    int mid = (s + e) / 2;
    v[level].push_back(a[mid]);
    recur(s, mid - 1, level + 1);
    recur(mid + 1, e, level + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;

    int n = (int)pow(2, k) - 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    recur(0, n, 1);
    for (int i = 1; i <= k; i++) {
        for (int num : v[i]) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}