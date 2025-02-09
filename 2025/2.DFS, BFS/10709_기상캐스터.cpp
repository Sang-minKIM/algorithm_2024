#include <bits/stdc++.h>
using namespace std;
int cnt = -1, h, w;
char c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c;
            if (c == 'c') {
                cnt = 0;
                cout << cnt << ' ';
                continue;
            } else if (cnt >= 0) {
                cnt++;
                cout << cnt << ' ';
            } else {
                cout << cnt << ' ';
            }
        }
        cout << '\n';
        cnt = -1;
    }

    return 0;
}