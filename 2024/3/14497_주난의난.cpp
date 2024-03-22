
#include <iostream>
#include <queue>

using namespace std;
#define y1 eeee

int y1, x1, y2, x2, n, m, visited[304][304], cnt, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
char a[304][304];

queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    x1--;
    y1--;
    x2--;
    y2--;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> a[y][x];
        }
    }

    q.push(y1 * 1000 + x1);
    visited[y1][x1] = 1;
    while (a[y2][x2] != '0') {
        cnt++;
        queue<int> temp;
        while (q.size()) {
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if (a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                } else {
                    q.push(1000 * ny + nx);
                }
            }
        }
        q = temp;
    }

    cout << visited[y2][x2];
    return 0;
}

// 멈추고 다시 가고를 queue 2개로 처리함 그리고 q를 쉽게 복사하기 위해 int형으로 씀