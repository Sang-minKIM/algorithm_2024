#include <bits/stdc++.h>
using namespace std;

string str;
int n, ret, cnt, a[200004];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else if (stk.size()) {
            a[i] = 1;
            a[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i]) {
            cnt++;
            ret = max(ret, cnt);
        } else {
            cnt = 0;
        }
    }
    cout << ret;
    return 0;
}
