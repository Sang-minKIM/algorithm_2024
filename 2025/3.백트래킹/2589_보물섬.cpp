#include <bits/stdc++.h>
using namespace std;
char a[51][51];
int v2[51][51], n, m, ly, lx, ret, buffer;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    v2[i][j] = 1;
    ly = i;
    lx = j;
    while (q.size()) {
        int y = 0, x = 0;
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'W' || v2[ny][nx] > 0) continue;
            q.push({ny, nx});
            v2[ny][nx] = v2[y][x] + 1;
            ly = ny;
            lx = nx;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    string bufferflush;
    getline(cin, bufferflush);
    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L') {
                bfs(i, j);
                ret = max(v2[ly][lx], ret);
                fill(&v2[0][0], &v2[0][0] + 51 * 51, 0);
            }
        }
    }
    cout << ret - 1;
    return 0;
}