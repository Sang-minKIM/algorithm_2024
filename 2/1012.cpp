#include <bits/stdc++.h>
using namespace std;
const int max_n = 54;
int arr[max_n][max_n];
int t, m, n, k, x, y, ret;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    arr[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >=n || nx < 0 || nx >= m) continue;
        if(arr[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int j = 0; j < t; j++) {
        cin >> m >> n >> k;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                if(arr[y][x]) {
                    dfs(y, x);
                    ret++;
                }
            }
        }
    cout << ret << "\n";
    ret = 0;
    }

    return 0;
}