#include <bits/stdc++.h>
using namespace std;
int max_safe = 1, n, arr[101][101], visited[101][101];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void dfs(int y, int x, int h) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
       int nx = x + dx[i];
       int ny = y + dy[i];
       if(nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
       if(visited[ny][nx]) continue;
       if(arr[ny][nx] <= h) continue;
       dfs(ny, nx, h);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int y = 0; y < n; y ++) {
        for(int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }
    for(int h = 0; h < 101; h++){
        int temp=0;
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < n; x++){
                if(visited[y][x]) continue;
                if(arr[y][x] <= h) continue;
                dfs(y, x, h);
                temp++;  
            }
        }
        max_safe = max(max_safe, temp);
        fill(&visited[0][0], &visited[n][n], 0);
    }
    cout << max_safe << "\n";
    return 0;
}
