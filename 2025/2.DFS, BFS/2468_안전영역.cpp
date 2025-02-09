#include <bits/stdc++.h>
using namespace std;
int h, n, a[102][102], v[102][102], cnt, mx, ny, nx;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x, int h) {
    v[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] <= h || v[ny][nx] == 1) continue;
        dfs(ny, nx, h);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int h = 0; h <= 100; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] > h && v[i][j] == 0) {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        mx = max(mx, cnt);
        cnt = 0;
        fill(&v[0][0], &v[0][0] + 102 * 102, 0);
    }
    cout << mx;

    return 0;
}