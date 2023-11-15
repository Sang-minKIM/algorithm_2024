// 알파벳

#include <bits/stdc++.h>
using namespace std;
int n, m, ret = 1;
char graph[21][21];
int visited[26];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

void dfs(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for(int i = 0; i< 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(visited[graph[ny][nx] - 'A'] == 1) continue;
        visited[graph[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt + 1);
        visited[graph[ny][nx] - 'A'] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cin >> graph[y][x];
        }
    }
    visited[graph[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ret << '\n';
    return 0;
}