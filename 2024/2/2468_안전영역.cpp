#include <bits/stdc++.h>
using namespace std;
int n, a[104][104], v[104][104], maxh, ret = 1, cnt, ny, nx;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x, int h) {
    v[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || v[ny][nx] == 1 || a[ny][nx] <= h) continue;
        dfs(ny, nx, h);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> a[y][x];
            maxh = max(maxh, a[y][x]);
        }
    }

    for (int h = 0; h < maxh; h++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (a[y][x] > h && v[y][x] == 0) {
                    dfs(y, x, h);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
        cnt = 0;
        memset(v, 0, sizeof(v));
    }

    cout << ret << '\n';
    return 0;
}
