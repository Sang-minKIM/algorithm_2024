#include <bits/stdc++.h>
using namespace std;
#define y1 xoxoxoxo

int a[101][101], n, m, k, x1, x2, y1, y2, cnt;
vector<int> v;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs(int y, int x) {
    a[y][x] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int h = 0; h < k; h++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) continue;
            dfs(i, j);
            v.push_back(cnt);
            cnt = 0;
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto c : v) {
        cout << c << ' ';
    }
    return 0;
}