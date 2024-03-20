#include <bits/stdc++.h>
using namespace std;

int arr[104][104], n, m, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, ny, nx, x, y;
queue<pair<int, int>> q;
string temp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        cin >> temp;
        for (int x = 0; x < m; x++) {
            arr[y][x] = temp[x] - '0';
        }
    }

    q.push({0, 0});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (arr[ny][nx] == 1) {
                arr[ny][nx] = arr[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout << arr[n - 1][m - 1] << '\n';

    return 0;
}
