#include <bits/stdc++.h>
using namespace std;
int m, n, k, a[101][101], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, x1, h1, x2, h2;
vector<int> areas;

int dfs(int y, int x) {
    a[y][x] = 1;
    int ret = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx>=n || ny >=m) continue;
        if(a[ny][nx]) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i =0; i < k; i++) {
        cin >> x1 >> h1 >> x2 >> h2;
        for(int y = h1; y < h2; y++) {
              fill(&a[y][x1], &a[y][x2], 1);
        }
      
    } 

    for(int y = 0; y < m; y++) { 
        for(int x = 0; x < n; x++) {
            if(a[y][x] == 0) {
                areas.push_back(dfs(y, x));
            }
        }
    }
    sort(areas.begin(), areas.end());
    cout << areas.size() << "\n";
    for(int v : areas) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}