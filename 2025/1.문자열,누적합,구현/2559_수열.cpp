#include <bits/stdc++.h>
using namespace std;
int n, k, a[100004], psum[100004], mx = -987654321;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = a[i] + psum[i - 1];
    }
    for (int i = 0; i <= n - k; i++) {
        mx = max(mx, psum[i + k] - psum[i]);
    }
    cout << mx;
    return 0;
}