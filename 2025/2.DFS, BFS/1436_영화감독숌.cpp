#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, i = 1, num = 666;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (i <= t) {
        if (to_string(num).find("666") != string::npos) {
            i++;
        }
        num++;
    }
    cout << num - 1;
    return 0;
}