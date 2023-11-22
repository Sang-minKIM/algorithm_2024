#include <bits/stdc++.h>
using namespace std;
int a[12][12], visited[12][12], mn = 987654321, n;
vector<pair<int, int>> emt;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int go(int y, int x) {
    visited[y][x] = 1;
    int ret = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (visited[ny][nx] == 1) return 5000;
        visited[ny][nx] = 1;
        ret += a[ny][nx];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> a[y][x];
            if (y > 0 && x > 0 && y < n - 1 && x < n - 1) {
                emt.push_back({y, x});
            }
        }
    }

    for (int i = 0; i < emt.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                int pay = 0;
                fill(&visited[0][0], &visited[0][0] + 12 * 12, 0);
                pay += go(emt[i].first, emt[i].second);
                pay += go(emt[j].first, emt[j].second);
                pay += go(emt[k].first, emt[k].second);
                mn = min(pay, mn);
            }
        }
    }

    cout << mn << '\n';

    return 0;
}