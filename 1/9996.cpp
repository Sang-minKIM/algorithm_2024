#include <bits/stdc++.h>
using namespace std;

int n;
string p, file, pre, suf;

int main() {
    cin >> n;
    cin >> p;
    int pos = p.find('*');
    pre = p.substr(0, pos);
    suf = p.substr(pos + 1);
    for (int i = 0; i < n; i++) {
        cin >> file;
        if (pre.size() + suf.size() > file.size()) {
            cout << "NE\n";
        } else {
            if (file.substr(0, pre.size()) == pre && file.substr(file.size() - suf.size()) == suf)
                cout << "DA\n";
            else
                cout << "NE\n";
        }
    }
    return 0;
}