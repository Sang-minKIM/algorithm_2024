#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, t, cnt, visited[1004];
vector<int> graph[1004];

void dfs(int here) {
    visited[here] = 1;
    for (int there : graph[here]) {
        if (visited[there]) continue;
        dfs(there);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            graph[i].clear();
        }
        fill(visited, visited + n + 1, 0);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            dfs(i);
            cnt++;
        }
        if (cnt == 1 && n == m + 1)
            cout << "tree" << '\n';
        else
            cout << "graph" << '\n';
        cnt = 0;
    }

    return 0;
}