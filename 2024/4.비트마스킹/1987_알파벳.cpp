#include <bits/stdc++.h>
using namespace std;
int n, m, ret, ny, nx;
char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x, int num, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        int next = (1 << (int)(a[ny][nx] - 'A'));
        if ((num & next) == 0) go(ny, nx, num | next, cnt + 1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> a[y][x];
        }
    }
    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
    cout << ret << '\n';

    return 0;
}