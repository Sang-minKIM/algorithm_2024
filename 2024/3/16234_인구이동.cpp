#include <bits/stdc++.h>
using namespace std;

int flag, n, l, r, a[54][54], visited[54][54], cnt, sum, ny, nx, ret;
vector<pair<int, int>> v;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool check(int y, int x, int ny, int nx) {
    int gap = abs(a[y][x] - a[ny][nx]);
    if (gap >= l && gap <= r) return true;
    return false;
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y, x});
    sum += a[y][x];
    cnt++;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if (check(y, x, ny, nx)) {
            flag = 1;
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> a[y][x];
        }
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (visited[y][x]) continue;

                v.clear();
                dfs(y, x);
                int avg = sum / cnt;
                for (auto yx : v) {
                    visited[yx.first][yx.second] = avg;
                }
                cnt = 0, sum = 0;
            }
        }

        copy(&visited[0][0], &visited[0][0] + 54 * 54, &a[0][0]);
        if (!flag) break;
        ret++;
        flag = 0;
    }
    cout << ret;

    return 0;
}
