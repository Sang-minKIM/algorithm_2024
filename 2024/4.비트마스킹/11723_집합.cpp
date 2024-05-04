#include <bits/stdc++.h>
using namespace std;
int n, s, x;
string cmd;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            s |= (1 << x);
        } else if (cmd == "remove") {
            cin >> x;
            s &= ~(1 << x);
        } else if (cmd == "check") {
            cin >> x;
            int ret = s & (1 << x) ? 1 : 0;
            cout << ret << '\n';
        } else if (cmd == "toggle") {
            cin >> x;
            s ^= (1 << x);
        } else if (cmd == "all") {
            s = (1 << 21) - 1;
        } else if (cmd == "empty") {
            s = 0;
        }
    }

    return 0;
}