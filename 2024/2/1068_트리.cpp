#include <bits/stdc++.h>
using namespace std;

int n, root, temp, del, cnt;

vector<int> a[51];

void dfs(int node) {
    int child = 0;
    for (int i = 0; i < a[node].size(); i++) {
        if (a[node][i] == del) continue;
        dfs(a[node][i]);
        child++;
    }
    if (child == 0) {
        cnt++;
        return;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1)
            root = i;
        else {
            a[temp].push_back(i);
        }
    }

    cin >> del;

    if (root != del) dfs(root);
    cout << cnt << '\n';
    return 0;
}

엣지 케이스 조심하기