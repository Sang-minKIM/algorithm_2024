#include <bits/stdc++.h>
using namespace std;
int n, m, dist[104], a[52][52], c[15], ret = 987654321;
vector<pair<int, int>> chic, home;

void combi(int cnt, int start) {
    if (cnt == m) {
        int dist = 0;
        for (int i = 0; i < home.size(); i++) {
            int mn = 987654321;
            for (int j = 0; j < cnt; j++) {
                int idx = c[j];
                int cy = chic[idx].first;
                int cx = chic[idx].second;
                int hy = home[i].first;
                int hx = home[i].second;
                int k = abs(cy - hy) + abs(cx - hx);
                mn = min(mn, k);
            }
            dist += mn;
        }
        ret = min(dist, ret);
    }
    for (int i = start; i < chic.size(); i++) {
        c[cnt] = i;
        combi(cnt + 1, i + 1);
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
            if (a[i][j] == 1) {
                home.push_back({i, j});
            } else if (a[i][j] == 2) {
                chic.push_back({i, j});
            }
        }
    }
    combi(0, 0);
    cout << ret;
    return 0;
}