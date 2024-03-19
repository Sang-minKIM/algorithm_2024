#include <bits/stdc++.h>
using namespace std;

int n, m, j, l = 1, r = 1, ap, ret;

int main() {
    cin >> n >> m >> j;
    r = m;
    for(int i = 0; i < j; i++) {
        cin >> ap;
        if(ap >= l && ap <= r) continue;
        if(ap > r) {
            int temp = ap - r;
            r += temp;
            l += temp;
            ret += temp;
        } else {
            int temp = l - ap;
            r -= temp;
            l -= temp;
            ret += temp;
        }
    }
    cout << ret << "\n";
    return 0;
}