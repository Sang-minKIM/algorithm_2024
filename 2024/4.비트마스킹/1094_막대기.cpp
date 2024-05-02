#include <bits/stdc++.h>
using namespace std;
int x, ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    for (int i = 0; (1 << i) <= 64; i++) {
        if (x & (1 << i)) ret++;
    }
    cout << ret;

    return 0;
}