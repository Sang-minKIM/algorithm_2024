#include <bits/stdc++.h>
using namespace std;
int m, n, k, xl, yl, xr, yr, area, cnt, a[104][104];
vector<int> v;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void dfs(int y, int x) {
    a[y][x] = 1;
    area++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= m || nx >= n || a[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> xl >> yl >> xr >> yr;
        for (int y = yl; y < yr; y++) {
            for (int x = xl; x < xr; x++) {
                a[y][x] = 1;
            }
        }
    }
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (a[y][x] == 0) {
                dfs(y, x);
                v.push_back(area);
                area = 0;
                cnt++;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (int e : v) cout << e << " ";

    return 0;
}

17분