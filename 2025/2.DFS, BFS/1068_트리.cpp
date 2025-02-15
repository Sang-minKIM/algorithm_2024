#include <bits/stdc++.h>
using namespace std;
int n, cnt, p[50], d;
vector<int> a[50], v;

void dfs(int node) {
    v.push_back(node);
    for (int c : a[node]) {
        dfs(c);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == -1) continue;
        a[p[i]].push_back(i);
    }
    cin >> d;
    dfs(d);

    for (int i = 0; i < n; i++) {
        if (find(v.begin(), v.end(), i) != v.end()) continue;

        if (a[i].size() == 0) cnt++;
        if (i == p[d] && a[i].size() == 1) cnt++;
    }
    cout << cnt;
    return 0;
}