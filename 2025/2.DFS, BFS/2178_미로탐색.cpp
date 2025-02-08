#include <bits/stdc++.h>
using namespace std;
int n, m, a[104][104], ny, nx, y, x;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
string input;
queue<pair<int, int>> q;

void bfs() {
    q.push({0, 0});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != 1) continue;
            a[ny][nx] = a[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            a[i][j] = int(input[j]) - 48;
        }
    }
    bfs();
    cout << a[n - 1][m - 1];
    return 0;
}