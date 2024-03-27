#include <bits/stdc++.h>
using namespace std;

int w, h, a[104][104];
char mp[104][104];
string temp;

void dfs(int y, int x, int d) {
    if (x - d < 0) return;
    if (mp[y][x - d] == 'c') {
        a[y][x] += d + 1;
        return;
    }
    dfs(y, x, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    memset(a, -1, sizeof(a));

    for (int i = 0; i < h; i++) {
        cin >> temp;
        for (int j = 0; j < w; j++) {
            mp[i][j] = temp[j];
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            dfs(y, x, 0);
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cout << a[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}