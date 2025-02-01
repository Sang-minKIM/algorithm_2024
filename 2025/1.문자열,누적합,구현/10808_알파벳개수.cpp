#include <bits/stdc++.h>
using namespace std;
int a[26];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (char c : s) {
        a[c - 'a']++;
    }
    for (int i : a) {
        cout << i << " ";
    }
    return 0;
}