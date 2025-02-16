#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, cnt[10004], mx, v[10004];
vector<int> c[10004];

int dfs(int i) {
    int cnt = 1;
    v[i] = 1;
    for (int next : c[i]) {
        if (v[next]) continue;
        cnt += dfs(next);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        c[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        fill(v, v + 10004, 0);
        cnt[i] = dfs(i);
        mx = max(mx, cnt[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == mx) {
            cout << i << ' ';
        }
    }

    return 0;
}