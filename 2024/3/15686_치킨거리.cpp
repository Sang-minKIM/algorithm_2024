#include <bits/stdc++.h>
using namespace std;

int n, m, a[54][54], ret = 987654321, visited[54][54];
vector<pair<int, int>> chiList, houseList;
vector<int> v;

int go() {
    int cnt = 0;
    for (auto house : houseList) {
        int mn = 987654321;
        for (auto idx : v) {
            mn = min(abs(house.first - chiList[idx].first) + abs(house.second - chiList[idx].second), mn);
        }
        cnt += mn;
    }
    return cnt;
}

void combi(int start) {
    if (v.size() == m) {
        ret = min(ret, go());
    }

    for (int i = start + 1; i < chiList.size(); i++) {
        v.push_back(i);
        combi(i);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                chiList.push_back({i, j});
            }
            if (a[i][j] == 1) {
                houseList.push_back({i, j});
            }
        }
    }
    combi(-1);

    cout << ret;

    return 0;
}