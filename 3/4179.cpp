#include<bits/stdc++.h>
using namespace std;

int n, m, fire_check[1004][1004], person_check[1004][1004], ret;
char arr[1004][1004];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int INF = 987654321;

vector<pair<int, int>> fire;
pair<int, int> j;
queue<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cin >> arr[y][x];
            if(arr[y][x] == 'J') j = {y, x};
            else if(arr[y][x] == 'F') {
                q.push({y,x});
                fire_check[y][x] = 1;
            }
        }
    }

    while(q.size()) {
        int y = 0, x=0;
        tie(y, x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || ny >= n || ny >= m) continue;
            if(fire_check[ny][nx] != INF || arr[ny][nx]=='#') continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    person_check[j.first][j.second] = 1;
    q.push(j);

    while(q.size()) {
          int y = 0, x=0;
        tie(y, x) = q.front();
        q.pop();

        if(x == m - 1 || y == n - 1 || x == 0 || y == 0){
            ret = person_check[y][x];
            break;
		}

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || ny >= n || ny >= m) continue;
            if(person_check[ny][nx] || arr[ny][nx]=='#') continue;
            if(fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
    return 0;
}

