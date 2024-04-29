#include <bits/stdc++.h>
using namespace std;
int n, l, a[104][104], b[104][104], ret;

void go(int a[104][104]) {
    for (int y = 0; y < n; y++) {
        int cnt = 1;
        int x;
        for (x = 0; x < n - 1; x++) {
            if (a[y][x] == a[y][x + 1])
                cnt++;
            else if (a[y][x] + 1 == a[y][x + 1] && cnt >= l)
                cnt = 1;
            else if (a[y][x] - 1 == a[y][x + 1] && cnt >= 0)
                cnt = 1 - l;
            else
                break;
        }
        if (x == n - 1 && cnt >= 0) ret++;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> a[y][x];
            b[x][y] = a[y][x];
        }
    }

    go(a);
    go(b);
    cout << ret << '\n';
    return 0;
}