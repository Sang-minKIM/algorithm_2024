#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> house, store, selected;
int n, m, temp, sum=987654321;

int go() {
    int ret = 0;
    for(int i = 0; i < house.size(); i++) {
        int mini = 100000;
        for(int j = 0; j < selected.size(); j++) {
            mini = min(abs(selected[j].first - house[i].first) + abs(selected[j].second - house[i].second) , mini);
        }
        ret += mini;
    }
    return ret;
}

void dfs(int start, int k) {
    if(k == m) {
        sum = min(sum, go());
        return;
    }
    for(int i = start; i < store.size(); i++) {
        selected.push_back(store[i]);
        dfs(i + 1, k + 1);
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            cin >> temp;
            if(temp == 1) house.push_back({y, x});
            if(temp == 2) store.push_back({y, x});
        }
    }
    dfs(0, 0);
    cout << sum << "\n";
    return 0;
}