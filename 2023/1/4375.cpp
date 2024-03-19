#include <bits/stdc++.h>
using namespace std;
int n;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n) {
        int cnt = 1;
        long long one = 1;
        while(one % n) {
            one = one * 10 + 1;
            one %= n;
            cnt ++;
        }
        cout << cnt << "\n";
    }
    return 0;
}