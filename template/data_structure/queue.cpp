#include <bits/stdc++.h>
using namespace std;
int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    queue<int> Q;
    for (int i = 1; i <= n; i++) Q.push(i);
    cout << '<';
    while (!Q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front();
        Q.pop();
        if (Q.size()) cout << ", ";
    }
    cout << '>';

    return 0;
}
