#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, five = 5, ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        while (n >= five) {
            ret += n / five;
            five *= 5;
        }
        five = 5;
        cout << ret << '\n';
        ret = 0;
    }
    return 0;
}