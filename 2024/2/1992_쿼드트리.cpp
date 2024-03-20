#include <bits/stdc++.h>
using namespace std;

int n;
char a[65][65];
string ans;

string quard(int ys, int xs, int range) {
    string ret = "";
    if (range == 1) {
        ret += a[ys][xs];
        return ret;
    }

    for (int y = ys; y < ys + range; y++) {
        for (int x = xs; x < xs + range; x++) {
            if (a[y][x] != a[ys][xs]) {
                ret = '(';
                ret += quard(ys, xs, range / 2);
                ret += quard(ys, xs + range / 2, range / 2);
                ret += quard(ys + range / 2, xs, range / 2);
                ret += quard(ys + range / 2, xs + range / 2, range / 2);
                ret += ')';
                return ret;
            }
        }
    }
    return ret + a[ys][xs];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ans = quard(0, 0, n);
    cout << ans;
    return 0;
}
