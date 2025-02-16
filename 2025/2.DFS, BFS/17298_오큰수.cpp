#include <bits/stdc++.h>
using namespace std;
int n, ret[1000004], a[1000004];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        while (true) {
            if (stk.size() == 0) {
                stk.push(a[i]);
                ret[i] = -1;
                break;
            }
            if (stk.top() > a[i]) {
                ret[i] = stk.top();
                stk.push(a[i]);
                break;
            } else if (stk.top() <= a[i]) {
                stk.pop();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }
    return 0;
}