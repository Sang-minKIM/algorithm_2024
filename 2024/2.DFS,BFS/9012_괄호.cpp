#include <bits/stdc++.h>
using namespace std;

int n;
string s;
bool flag = true;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> s;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push('(');
            } else {
                if (stk.empty()) {
                    flag = false;
                    break;
                } else {
                    stk.pop();
                }
            }
        }
        if (stk.size()) {
            flag = false;
        }
        if (flag) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        flag = true;
    }

    return 0;
}