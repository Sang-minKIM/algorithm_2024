#include <bits/stdc++.h>
using namespace std;
int n;
string s, e, f, p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    int i = 0;
    while (p[i] != '*') {
        s += p[i];
        i++;
    }
    i++;
    while (i < p.size()) {
        e += p[i];
        i++;
    }
    for (int i = 0; i < n; i++) {
        cin >> f;
        if (p.size() - 1 > f.size()) {
            cout << "NE" << '\n';
            continue;
        }
        if (f.substr(0, s.size()) != s || f.substr(f.size() - e.size(), e.size()) != e) {
            cout << "NE" << '\n';
        } else {
            cout << "DA" << '\n';
        }
    }

    return 0;
}