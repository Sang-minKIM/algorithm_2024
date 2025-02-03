#include <bits/stdc++.h>
using namespace std;
int n, m;
string temp;
map<string, string> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        mp[temp] = to_string(i);
        mp[to_string(i)] = temp;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << mp[temp] << '\n';
    }
    return 0;
}