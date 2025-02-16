#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, mn, mx, a[51][51], visited[51][51], flag, day, people, country;
vector<pair<int, int>> v, b[51][51];

void check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                int gap = abs(a[ny][nx] - a[i][j]);
                if (gap >= mn && gap <= mx) {
                    b[i][j].push_back({ny, nx});
                    flag = 1;
                }
            }
        }
    }
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    people += a[y][x];
    country++;
    v.push_back({y, x});
    for (auto i : b[y][x]) {
        int ny = i.first;
        int nx = i.second;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mn >> mx;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        check();
        if (flag == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                dfs(i, j);
                int avg = people / country;
                for (auto i : v) {
                    int y = i.first;
                    int x = i.second;
                    a[y][x] = avg;
                }
                people = 0;
                country = 0;
                v.clear();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[i][j].clear();
            }
        }
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        day++;
        flag = 0;
    }
    cout << day;
    return 0;
}