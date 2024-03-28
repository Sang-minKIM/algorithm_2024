#include <bits/stdc++.h>

using namespace std;
int n, k, visited[500004][2], ok;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }

    int time = 1;
    visited[n][0] = 1;
    q.push(n);
    while (q.size()) {
        k += time;
        if (k > 500000) break;
        if (visited[k][time % 2]) {
            ok = 1;
            break;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int x = q.front();
            q.pop();
            for (int nx : {x + 1, x - 1, x * 2}) {
                if (nx > 500000 || nx < 0 || visited[nx][time % 2]) continue;
                visited[nx][time % 2] = visited[x][(time + 1) % 2] + 1;

                if (nx == k) {
                    ok = 1;
                    break;
                }
                q.push(nx);
            }
            if (ok) break;
        }
        if (ok) break;
        time++;
    }
    if (ok)
        cout << time << '\n';
    else
        cout << -1 << '\n';

    return 0;
}

// 플루드 필 -> qSize를 저장해서 단계별로 구분해서 탐색할 수 있다.