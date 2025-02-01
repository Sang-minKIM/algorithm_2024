#include <bits/stdc++.h>
using namespace std;
string s, rs;
bool ans = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    rs = s;
    reverse(rs.begin(), rs.end());
    for (int i = 0; i < s.size(); i++) {
        if (rs[i] != s[i]) {
            ans = 0;
            break;
        }
    }
    cout << ans;
    return 0;
}