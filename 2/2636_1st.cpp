#include <bits/stdc++.h>
using namespace std;

int n, m, arr[104][104], visited[104][104], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, t, ret = 104 * 104;

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 1) arr[ny][nx] = 2;
        if(arr[ny][nx] == 0) dfs(ny, nx);
    }
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

    while(true) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        dfs(0, 0);
        int cnt = 0; 
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                if(arr[y][x] == 2) {
                    arr[y][x] = 0;
                    cnt++;
                }
            }
        }

        if(cnt) ret = min(ret, cnt);
        else break;
        t++;
    }
    
    cout << t << "\n" << ret << "\n";
    return 0;
}