#include <bits/stdc++.h>
using namespace std;
int n, m, graph[8][8], visited[8][8], dx[] = {0 , 1, 0, -1}, dy[] = {1, 0, -1, 0}, ret;
vector<pair<int, int>> wallList, virusList;

void dfs(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n || graph[ny][nx] == 1 ) continue;
        if(visited[ny][nx] == 0) {
            visited[ny][nx] = 1;
            dfs(ny, nx);
            
        } 
    }
}

int solve() {
    fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);
    for(int l = 0; l < virusList.size(); l++) {
        int y = 0,  x = 0;
        tie(y, x) = virusList[l];
        visited[y][x] = 1;
        dfs(y, x);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == 0  && visited[i][j] == 0) cnt++;
        } 
    }
    return cnt;
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cin >> graph[y][x];
            if(graph[y][x] == 0) wallList.push_back({y, x});
            if(graph[y][x] == 2) virusList.push_back({y, x});
        }
    }
    for(int i = 0; i < wallList.size(); i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                graph[wallList[i].first][wallList[i].second] = 1;
                graph[wallList[j].first][wallList[j].second] = 1;
                graph[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                graph[wallList[i].first][wallList[i].second] = 0;
                graph[wallList[j].first][wallList[j].second] = 0;
                graph[wallList[k].first][wallList[k].second] = 0;

            }
        }
    }

    cout << ret << "\n";
    return 0;
}