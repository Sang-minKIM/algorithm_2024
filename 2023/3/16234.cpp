#include <bits/stdc++.h>
using namespace std;

int n, l, r, arr[54][54], visited[54][54], cnt, sum;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>>  &v) {
    visited[y][x] = 1;
    sum += arr[y][x];
    v.push_back({y, x});

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(visited[ny][nx]) continue;
        int sub = abs(arr[y][x] - arr[ny][nx]);
        if(sub >= l && sub <= r) {
            dfs(ny, nx, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> r;
    
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            cin >> arr[y][x];
        }
    }



    while(true) {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < n; x++) {
                if(!visited[y][x]) {

                    v.clear();
                    sum = 0;
                    dfs(y, x, v);
                    if(v.size() == 1) continue;
                    for(pair<int, int> p : v)  {
                        arr[p.first][p.second] = sum / v.size();
                        flag = 1;

                    }
                }
            } 
        }

        if(!flag) break;
        cnt++;

    }

    cout << cnt << "\n";

    return 0;
}