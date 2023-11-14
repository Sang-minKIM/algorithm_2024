// 주난의 난
#include<bits/stdc++.h>
using namespace std;
#define y1 eeeeeee


int n, m, x1, y1, x2, y2, dy[] = {1,0,-1,0}, dx[] = {0,1,0,-1};
int visited[304][304];
char graph[304][304];

queue<int> q;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    x1--; y1--; x2--; y2--;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cin >> graph[y][x];
        }
    }
   
    q.push(y1 * 1000 + x1);
    visited[y1][x1] = 1;
    int cnt = 0;

    while(graph[y2][x2] != '0') {
        cnt++;
        queue<int> temp;
        while(q.size()){
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(graph[ny][nx] != '0') {
                    graph[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000 * ny + nx);
            }
        }
        q = temp;
    }
    cout << visited[y2][x2] << "\n";


    return 0;
}