#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, a[52][52], cx, cy, cnt;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x) {
    a[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int l = 0; l < t; l++) {
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> cx >> cy;
            a[cy][cx] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) continue;
                cnt++;
                dfs(i, j);
            }
        }
        fill(&a[0][0], &a[0][0] + 52 * 52, 0);
        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}