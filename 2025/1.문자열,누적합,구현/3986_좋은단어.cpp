#include <bits/stdc++.h>
using namespace std;
int n, ans;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        stack<char> stk;
        cin >> s;
        for (char c : s) {
            if (stk.size() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        if (stk.size() == 0) ans++;
    }
    cout << ans;
    return 0;
}