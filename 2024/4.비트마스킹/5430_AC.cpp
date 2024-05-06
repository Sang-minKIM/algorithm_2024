#include <bits/stdc++.h>
using namespace std;
int t, n, flag = 1;
string p, arr;
deque<int> a;

void go() {
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == 'R')
            flag *= -1;
        else if (p[i] == 'D') {
            if (a.size() < 1) {
                cout << "error" << '\n';
                return;
            }
            if (flag > 0) {
                a.pop_front();
            } else if (flag < 0) {
                a.pop_back();
            }
        }
    }
    cout << '[';
    if (flag < 0) {
        reverse(a.begin(), a.end());
    }
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1) cout << ',';
    }

    cout << ']' << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> p >> n >> arr;
        flag = 1;
        a.clear();
        int x = 0;
        for (char c : arr) {
            if (c == '[' || c == ']') continue;
            if (c >= '0' && c <= '9')
                x = x * 10 + c - '0';
            else {
                if (x > 0) a.push_back(x);
                x = 0;
            }
        }
        if (x > 0) a.push_back(x);
        go();
    }

    return 0;
}
