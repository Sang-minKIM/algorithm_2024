#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, x, y, a[51][51], ret;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    a[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int T = 0; T < t; T++) {
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << '\n';
        ret = 0;
    }

    return 0;
}
