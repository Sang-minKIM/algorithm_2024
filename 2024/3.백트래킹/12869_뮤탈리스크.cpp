#include <bits/stdc++.h>

using namespace std;
int a[6][3] = {{1, 3, 9}, {1, 9, 3}, {3, 1, 9}, {3, 9, 1}, {9, 1, 3}, {9, 3, 1}}, n, scv[3], visited[64][64][64];
struct A {
    int a, b, c;
};

queue<A> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> scv[i];
    }
    q.push({scv[0], scv[1], scv[2]});
    visited[scv[0]][scv[1]][scv[2]] = 1;
    while (q.size()) {
        int x = q.front().a;
        int y = q.front().b;
        int z = q.front().c;
        q.pop();
        if (visited[0][0][0]) break;

        for (int i = 0; i < 6; i++) {
            int nx = max(x - a[i][0], 0);
            int ny = max(y - a[i][1], 0);
            int nz = max(z - a[i][2], 0);
            if (visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    cout << visited[0][0][0] - 1;
    return 0;
}