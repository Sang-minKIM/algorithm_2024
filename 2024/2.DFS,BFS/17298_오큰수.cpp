#include <bits/stdc++.h>
using namespace std;

int n, a[1000004];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        while (stk.size() && a[stk.top()] < a[i]) {
            a[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }

    while (stk.size()) {
        a[stk.top()] = -1;
        stk.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}