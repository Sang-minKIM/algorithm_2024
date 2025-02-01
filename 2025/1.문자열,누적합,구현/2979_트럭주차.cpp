#include <bits/stdc++.h>
using namespace std;
int p[4], a[104], s, e, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 3; i++) {
        cin >> p[i];
        p[i] *= i;
    }
    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        for (int i = s; i < e; i++) {
            a[i]++;
        }
    }
    for (int i = 1; i < 101; i++) {
        ans += p[a[i]];
    }
    cout << ans;
    return 0;
}