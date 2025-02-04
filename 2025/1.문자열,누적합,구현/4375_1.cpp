#include <bits/stdc++.h>
using namespace std;
long long n, cnt = 1, mod = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        while (mod % n) {
            mod = (mod * 10 + 1) % n;
            cnt++;
        }
        cout << cnt << '\n';
        cnt = 1;
        mod = 1;
    }
    return 0;
}