#include <bits/stdc++.h>
using namespace std;
int n, m, a[104][104], visited[104][104], t, c;
vector<pair<int, int>> v;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if (a[ny][nx] == 1) {
            v.push_back({ny, nx});
            visited[ny][nx] = 1;
        } else {
            dfs(ny, nx);
        }
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

    while (true) {
        memset(visited, 0, sizeof(visited));
        v.clear();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
                    if (visited[y][x] == 0) {
                        dfs(y, x);
                    }
                }
            }
        }
        if (v.size() == 0) {
            cout << t << '\n' << c;
            return 0;
        }
        for (auto yx : v) {
            int y = 0, x = 0;
            tie(y, x) = yx;
            a[y][x] = 0;
        }
        t++;
        c = v.size();
    }

    return 0;
}