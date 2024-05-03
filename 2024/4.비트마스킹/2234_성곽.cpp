#include <bits/stdc++.h>
using namespace std;
int n, m, a[51][51], b[51][51], area[2504], ret1, ret2, cnt;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

void dfs(int y, int x) {
    b[y][x] = cnt;
    area[cnt]++;
    for (int i = 0; i < 4; i++) {
        if (a[y][x] & (1 << i)) continue;
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (b[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> a[y][x];
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (b[y][x]) continue;
            cnt++;
            dfs(y, x);
            ret1 = max(ret1, area[cnt]);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (y + 1 < n) {
                if (b[y][x] != b[y + 1][x]) ret2 = max(ret2, area[b[y][x]] + area[b[y + 1][x]]);
            }
            if (x + 1 < m) {
                if (b[y][x] != b[y][x + 1]) ret2 = max(ret2, area[b[y][x]] + area[b[y][x + 1]]);
            }
        }
    }

    cout << cnt << '\n' << ret1 << '\n' << ret2;

    return 0;
}