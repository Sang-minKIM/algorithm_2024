#include <bits/stdc++.h>
using namespace std;

int n, pos;
string str, name, pre, suf;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;
    pos = str.find('*');
    pre = str.substr(0, pos);
    suf = str.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> name;
        if (name.length() < str.length() - 1) {
            cout << "NE" << '\n';
            continue;
        }
        if (pre == name.substr(0, pos) && suf == name.substr(name.length() - suf.length())) {
            cout << "DA" << '\n';
            continue;
        }
        cout << "NE" << '\n';
    }

    return 0;
}