#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, visited[10004], cnt, maxC;
vector<int> arr[10004], v;

int dfs(int here) {
    visited[here] = 1;
    int cnt = 1;
    for (int there : arr[here]) {
        if (visited[there]) continue;
        cnt += dfs(there);
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
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i].size() == 0) continue;
        memset(visited, 0, sizeof(visited));
        cnt = dfs(i);
        if (cnt == maxC) {
            v.push_back(i);
        } else if (cnt > maxC) {
            v.clear();
            v.push_back(i);
            maxC = cnt;
        }
    }

    for (int ret : v) {
        cout << ret << " ";
    }

    return 0;
}
v 대신 array를 써서 cnt를 저장하고 max 값만 갱신한 다음에 array 돌면서 max 값과 같은 애들만 출력하는 식으로 할 수도 있음
