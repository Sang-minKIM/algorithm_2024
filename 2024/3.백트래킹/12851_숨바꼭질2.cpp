#include <bits/stdc++.h>

using namespace std;
int n, k, visited[200004], cnt[200004];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int nx : {x + 1, x - 1, x * 2}) {
            if (nx > 200000 || nx < 0) continue;

            if (visited[nx] == visited[x] + 1) {
                cnt[nx] += cnt[x];
            } else if (visited[nx] == 0) {
                visited[nx] = visited[x] + 1;
                cnt[nx] = cnt[x];
                q.push(nx);
            }
        }
    }

    cout << visited[k] - 1 << '\n' << cnt[k];
    return 0;
}