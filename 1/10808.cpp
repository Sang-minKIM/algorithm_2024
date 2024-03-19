// 알파벳 개수

#include <bits/stdc++.h>
using namespace std;

int a[26];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (char c : s) {
        a[c - 'a']++;
    }

    for (int ans : a) {
        cout << ans << " ";
    }
    return 0;
}