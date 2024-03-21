#include <bits/stdc++.h>
using namespace std;
int n, m, a[10][10], visited[10][10], ret;
vector<pair<int, int>> emptyList, virusList;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] == 1) continue;
        if (a[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

void go() {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < virusList.size(); i++) {
        int x = 0, y = 0;
        tie(y, x) = virusList[i];

        dfs(y, x);
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (a[y][x] == 0 && visited[y][x] == 0) {
                cnt++;
            }
        }
    }
    ret = max(ret, cnt);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> a[y][x];
            if (a[y][x] == 0) {
                emptyList.push_back({y, x});
            } else if (a[y][x] == 2) {
                virusList.push_back({y, x});
            }
        }
    }

    for (int i = 0; i < emptyList.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                a[emptyList[i].first][emptyList[i].second] = 1;
                a[emptyList[j].first][emptyList[j].second] = 1;
                a[emptyList[k].first][emptyList[k].second] = 1;
                go();
                a[emptyList[i].first][emptyList[i].second] = 0;
                a[emptyList[j].first][emptyList[j].second] = 0;
                a[emptyList[k].first][emptyList[k].second] = 0;
            }
        }
    }

    cout << ret;

    return 0;
}