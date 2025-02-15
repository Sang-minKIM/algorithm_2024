#include <bits/stdc++.h>
using namespace std;
int a[104][104], v[104][104], n, m, cnt, hour, cheese = 1;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    v[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || v[ny][nx] == 1) continue;
        if (a[ny][nx] == 0) {
            dfs(ny, nx);
        } else if (a[ny][nx] == 1) {
            a[ny][nx] = 2;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    while (cheese) {
        cheese = 0;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && v[i][j] == 0) {
                    dfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2) {
                    a[i][j] = 0;
                    cnt++;
                }
                if (a[i][j] == 1) {
                    cheese++;
                }
            }
        }
        hour++;
        fill(&v[0][0], &v[0][0] + 104 * 104, 0);
    }
    cout << hour << '\n' << cnt;
    return 0;
}