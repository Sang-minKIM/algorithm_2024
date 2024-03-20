#include <bits/stdc++.h>
using namespace std;

int n, c, a[1004];
map<int, pair<int, int>> mp;

bool cmp(int a, int b) {
    if (mp[a].first == mp[b].first) {
        return mp[a].second < mp[b].second;
    }
    return mp[a].first > mp[b].first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mp[a[i]].first) {
            mp[a[i]].first++;
        } else {
            mp[a[i]].first = 1;
            mp[a[i]].second = i;
        }
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}

25분