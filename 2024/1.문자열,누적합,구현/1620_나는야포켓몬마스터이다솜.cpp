#include <bits/stdc++.h>
using namespace std;

int n, m;
string temp, arr[100004];
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        atoi(temp.c_str()) ? cout << arr[atoi(temp.c_str())] << '\n' : cout << mp[temp] << '\n';
    }

    return 0;
}