#include <bits/stdc++.h>
using namespace std;
int n, m, a[4][4], ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < m; x++) {
            a[y][x] = s[x] - '0';
        }
    }
    for (int s = 0; s < (1 << (n * m)); s++) {
        int sum = 0;
        for (int y = 0; y < n; y++) {
            int cur = 0;
            for (int x = 0; x < m; x++) {
                int k = y * m + x;
                if ((s & (1 << k)) == 0) {
                    cur = cur * 10 + a[y][x];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for (int x = 0; x < m; x++) {
            int cur = 0;
            for (int y = 0; y < n; y++) {
                int k = y * m + x;
                if ((s & (1 << k)) != 0) {
                    cur = cur * 10 + a[y][x];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }

    cout << ret;

    return 0;
}