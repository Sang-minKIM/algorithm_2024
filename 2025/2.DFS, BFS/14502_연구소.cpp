#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> empty, virus;
int a[9][9], n, m, mx;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    a[y][x] = 2;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx > m || a[ny][nx] != 0) continue;
        dfs(ny, nx);
    }
}

void count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cnt++;
            }
        }
    }
    mx = max(mx, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) empty.push_back({i, j});
            if (a[i][j] == 2) virus.push_back({i, j});
        }
    }
    for (int i = 0; i < empty.size(); i++) {
        for (int j = i + 1; j < empty.size(); j++) {
            for (int k = j + 1; k < empty.size(); k++) {
                a[empty[k].first][empty[k].second] = 1;
                a[empty[j].first][empty[j].second] = 1;
                a[empty[i].first][empty[i].second] = 1;
                for (int z = 0; z < virus.size(); z++) {
                    dfs(virus[z].first, virus[z].second);
                }
                count();
                for (int g = 0; g < empty.size(); g++) {
                    a[empty[g].first][empty[g].second] = 0;
                }
            }
        }
    }
    cout << mx;

    return 0;
}