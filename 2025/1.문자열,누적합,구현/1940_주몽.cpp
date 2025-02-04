#include <bits/stdc++.h>
using namespace std;
int n, m, a[15004], cnt, l, r, sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    r = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    while (l < r) {
        sum = a[l] + a[r];
        if (sum == m) {
            cnt++;
            l++;
        } else if (sum < m) {
            l++;
        } else {
            r--;
        }
    }
    cout << cnt;

    return 0;
}