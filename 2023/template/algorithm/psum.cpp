// 누적합

#include <bits/stdc++.h>
using namespace std;
int n, k, psum[100004], temp, msum = -1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
  
    for(int i=1; i<=n; i++) {
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    for(int i = k; i <= n; i++) {
       msum = max(msum ,psum[i] - psum[i - k]);
    }
    cout << msum << "\n";
    return 0;
}