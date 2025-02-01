#include <bits/stdc++.h>
using namespace std;
int n, a[26];
string s;
bool flag;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] > 4) {
            cout << char(i + 'a');
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "PREDAJA";
    }

    return 0;
}