#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[11], m, temp, ret = INF, comp[11], visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    // dfs로 탐색한 구역 수 기록, 인구 수 총합 기록
    pair<int, int> ret = {1, a[here]};
    for (int there : adj[here]) {
        // 같은 선거구만 탐색
        if (comp[there] != value) continue;
        if (visited[there]) continue;
        pair<int, int> _temp = dfs(there, value);
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            adj[i].push_back(temp);
        }
    }
    // 비트 마스킹
    for (int i = 1; i < (1 << n) - 1; i++) {
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // 켜져있으면 1, 그리고 켜진 구역 idx저장
                comp[j + 1] = 1;
                idx1 = j + 1;
            } else {
                // 꺼진 구역 idx 저장
                idx2 = j + 1;
            }
        }
        // 연결 체크, 꺼진 거 dfs, 켜진거 dfs, 구역 개수와 인구수를 각각 받는다.
        pair<int, int> comp1 = dfs(idx1, 1);
        pair<int, int> comp2 = dfs(idx2, 0);
        // 구역이 연결되어 있다면 인구 최솟값 업데이트
        if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
    }
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}