#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, one = 1, cnt = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n) {
        while (one % n) {
            one = (10 * one + 1) % n;
            cnt++;
        }
        cout << cnt << '\n';
        cnt = 1;
        one = 1;
    }

    return 0;
}
