#include <bits/stdc++.h>
using namespace std;

int n, dp[64][64][64], scv[3], visited[64][64][64];

int mutal[6][3] = {{1,3,9}, {1,9,3}, {3,1,9}, {3,9,1}, {9,3,1}, {9,1,3}};

struct A{
    int a, b, c;
};

queue<A> q;

int bfs(int a, int b, int c) {
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while(q.size()) {
        int x = q.front().a;
        int y = q.front().b;
        int z = q.front().c;
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++) {
            int nx = max(0, x - mutal[i][0]);
            int ny = max(0, y - mutal[i][1]);
            int nz = max(0, z - mutal[i][2]);
            if(visited[nx][ny][nz]) continue;
            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }
    return visited[0][0][0] - 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> scv[i];
    }
    cout << bfs(scv[0], scv[1], scv[2]) << "\n";

    return 0;
}


