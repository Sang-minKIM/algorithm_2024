#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll calc(ll x, ll y) {
    if (y == 1) return x % c;

    ll ret = calc(x, y / 2);
    ret = (ret * ret) % c;
    if (y % 2) {
        ret = (ret * x) % c;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    cout << calc(a, b) << '\n';
    return 0;
}