#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, i = 1, num = 666;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        stack<char> stk;
        bool flag = 1;
        for (char c : str) {
            if (c == '(') {
                stk.push(c);
            } else {
                if (stk.size()) {
                    stk.pop();
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        (stk.size() || flag == 0) ? cout << "NO" << '\n' : cout << "YES" << '\n';
    }
    return 0;
}