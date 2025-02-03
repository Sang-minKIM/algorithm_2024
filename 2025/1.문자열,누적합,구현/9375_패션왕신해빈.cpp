#include <bits/stdc++.h>
using namespace std;
int t, n, ans = 1;
map<string, int> mp;
string temp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> temp >> temp;
            mp[temp]++;
        }
        for (auto k : mp) {
            ans *= k.second + 1;
        }
        cout << ans - 1 << '\n';
        ans = 1;
        mp.clear();
    }

    return 0;
}