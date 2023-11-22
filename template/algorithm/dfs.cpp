// dfs 연구소

#include <bits/stdc++.h>
using namespace std;

int graph[8][8], visited[8][8], ret, n, m;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

vector<pair<int, int>> emptyList, virusList;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] == 1) continue;
        if (graph[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
    return;
}

int virus() {
    fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
    for (int i = 0; i < virusList.size(); i++) {
        int x = 0;
        int y = 0;
        tie(y, x) = virusList[i];
        if (!visited[y][x]) dfs(y, x);
    }
    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (visited[y][x] == 0 && graph[y][x] == 0) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> graph[y][x];
            if (graph[y][x] == 0) emptyList.push_back({y, x});
            if (graph[y][x] == 2) virusList.push_back({y, x});
        }
    }

    for (int i = 0; i < emptyList.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                graph[emptyList[i].first][emptyList[i].second] = 1;
                graph[emptyList[j].first][emptyList[j].second] = 1;
                graph[emptyList[k].first][emptyList[k].second] = 1;
                ret = max(ret, virus());
                graph[emptyList[i].first][emptyList[i].second] = 0;
                graph[emptyList[j].first][emptyList[j].second] = 0;
                graph[emptyList[k].first][emptyList[k].second] = 0;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
