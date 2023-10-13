#include <bits/stdc++.h>
using namespace std;
int n, m, visited[51][51], dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0}, mx;
char arr[51][51];


void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
            if(arr[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cin >> arr[y][x];
        }
    }

     for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(arr[y][x] == 'L') bfs(y, x);
        }
    }

    cout << mx - 1 << "\n";
    return 0;
}