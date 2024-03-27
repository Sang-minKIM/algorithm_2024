#include <bits/stdc++.h>
using namespace std;

int n, m, visitFire[1004][1004], visitJ[1004][1004], sy, sx, ret;
char a[1004][1004];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const int INF = 987654321;

queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    fill(&visitFire[0][0], &visitFire[0][0] + 1004 * 1004, INF);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> a[y][x];
            if (a[y][x] == 'J') {
                sy = y;
                sx = x;
            }
            if (a[y][x] == 'F') {
                q.push({y, x});
                visitFire[y][x] = 1;
            }
        }
    }

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == '#' || visitFire[ny][nx] != INF) continue;
            visitFire[ny][nx] = visitFire[y][x] + 1;
            q.push({ny, nx});
        }
    }

    visitJ[sy][sx] = 1;
    q.push({sy, sx});

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
            ret = visitJ[y][x];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || ny >= n || ny >= m) continue;
            if (visitJ[ny][nx] || a[ny][nx] == '#' || visitFire[ny][nx] <= visitJ[y][x] + 1) continue;
            visitJ[ny][nx] = visitJ[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if (ret)
        cout << ret;
    else
        cout << "IMPOSSIBLE";

    return 0;
}