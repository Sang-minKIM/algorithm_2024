#include <bits/stdc++.h>
using namespace std;
vector<int> arr[10004];
int table[10004], visited[10004], n, m, a, b, mx;

int dfs(int here) {
    int cnt = 1;
    visited[here] = 1;
    for(int there : arr[here]) {
        if(visited[there]) continue;
        cnt += dfs(there);
    }
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[b].push_back(a);
    }

    for(int i = 1; i <=n; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        table[i] = dfs(i);
        mx = max(table[i], mx);
    }

    for(int i = 1; i <= n; i++) {
        if(mx == table[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}