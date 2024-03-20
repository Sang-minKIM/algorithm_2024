#include <bits/stdc++.h>
using namespace std;

int n, m, j, l, r, cnt, spot;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> j;
    l = 1;
    r = l + m - 1;
    for (int i = 0; i < j; i++) {
        cin >> spot;
        if (spot > r) {
            cnt += spot - r;
            r = spot;
            l = r - m + 1;
            continue;
        }
        if (spot < l) {
            cnt += l - spot;
            l = spot;
            r = l + m - 1;
            continue;
        }
    }

    cout << cnt;
    return 0;
}

20분