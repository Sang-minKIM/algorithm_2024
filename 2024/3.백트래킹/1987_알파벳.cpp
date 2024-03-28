#include <bits/stdc++.h>

using namespace std;
int n, m, visited[21][21], alpha[26], ret;
char a[21][21];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x, int depth) {
    ret = max(ret, depth);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || alpha[a[ny][nx] - 'A']) continue;
        visited[ny][nx] = 1;
        alpha[a[ny][nx] - 'A'] = 1;
        dfs(ny, nx, depth + 1);
        visited[ny][nx] = 0;
        alpha[a[ny][nx] - 'A'] = 0;
    }
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

    visited[0][0] = 1;
    alpha[a[0][0] - 'A'] = 1;

    dfs(0, 0, 1);

    cout << ret << '\n';

    return 0;
}