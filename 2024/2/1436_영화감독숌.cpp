#include <bits/stdc++.h>
using namespace std;

int n, num, arr[10004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int i = 1;
    num = 666;
    while (i <= n) {
        if (to_string(num).find("666") != string::npos) {
            arr[i] = num;
            i++;
        }
        num++;
    }
    cout << arr[n];

    return 0;
}