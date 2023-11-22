#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int n, m, a[max_n][max_n], x, y;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
string temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        cin >> temp;
        for (int x = 0; x < m; x++) {
            a[y][x] = temp[x] - '0';
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (a[ny][nx] == 1) {
                a[ny][nx] = a[y][x] + 1;

                q.push({ny, nx});
            }
        }
    }
    cout << a[n - 1][m - 1] << "\n";
    return 0;
}