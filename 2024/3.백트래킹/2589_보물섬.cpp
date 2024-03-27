#include <bits/stdc++.h>
using namespace std;

int m, n, ret, visited[51][51];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

char a[51][51];
struct Triple {
    int a, b, c;
};

int bfs(int sy, int sx) {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    queue<Triple> q;

    q.push({sy, sx, 0});
    visited[sy][sx] = 1;
    while (q.size()) {
        int y = q.front().a, x = q.front().b, d = q.front().c;
        cnt = d;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'W') continue;
            visited[ny][nx] = 1;
            q.push({ny, nx, d + 1});
        }
    }

    return cnt;
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

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] == 'L') {
                ret = max(ret, bfs(y, x));
            }
        }
    }

    cout << ret;

    return 0;
}

// 그냥 visited를 이용해서 했으면 구조체 안써도 될듯