#include <bits/stdc++.h>
using namespace std;

string str;
int n, ret;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> str;
    stk.push(-1);
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.size()) {
                ret = max(ret, i - stk.top());
            } else {
                stk.push(i);
            }
        }
    }
    cout << ret;
    return 0;
}
