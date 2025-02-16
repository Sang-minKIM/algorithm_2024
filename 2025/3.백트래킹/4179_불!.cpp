#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, f[1004][1004], j[1004][1004], ret, sy, sx;
char a[1004][1004];
queue<pair<int, int>> q;

int bfsj(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    j[y][x] = 1;
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                return j[y][x];
            }
            if (a[ny][nx] == '#' || a[ny][nx] == 'F' || (f[ny][nx] && f[ny][nx] <= j[y][x] + 1) || j[ny][nx]) continue;
            j[ny][nx] = j[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return 0;
}

void bfsf() {
    int y = 0, x = 0;
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == '#' || f[ny][nx]) continue;
            f[ny][nx] = f[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                q.push({i, j});
                f[i][j] = 1;
            }
            if (a[i][j] == 'J') {
                sy = i;
                sx = j;
            }
        }
    }
    bfsf();
    ret = bfsj(sy, sx);
    ret ? cout << ret : cout << "IMPOSSIBLE";
    return 0;
}

불이 없다는 반례를 생각하지 못해서 한참 고민함