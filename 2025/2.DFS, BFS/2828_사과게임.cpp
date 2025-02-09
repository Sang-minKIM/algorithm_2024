#include <bits/stdc++.h>
using namespace std;
int s, e, n, m, j, cnt, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> j;
    s = 1;
    e = m;
    for (int i = 0; i < j; i++) {
        cin >> t;
        while (t < s || e < t) {
            if (t < s) {
                cnt++;
                s--;
                e--;
            } else if (t > e) {
                cnt++;
                s++;
                e++;
            }
        }
    }
    cout << cnt;
    return 0;
}