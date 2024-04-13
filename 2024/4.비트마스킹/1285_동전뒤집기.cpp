#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[21], ret = INF;
string s;

void go(int here) {
    if (here == n + 1) {
        int sum = 0;
        for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] & i) cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }

    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'T') a[i] |= (1 << j);
        }
    }
    go(1);
    cout << ret << '\n';
    return 0;
}