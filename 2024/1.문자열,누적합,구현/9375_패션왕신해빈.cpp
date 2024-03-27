#include <bits/stdc++.h>
using namespace std;

int t, n, ans = 1;
string v, key;
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v >> key;
            if (mp[key])
                mp[key]++;
            else
                mp[key] = 1;
        }
        for (auto it : mp) {
            ans *= it.second + 1;
        }
        cout << ans - 1 << '\n';
        mp.clear();
        ans = 1;
    }

    return 0;
}
