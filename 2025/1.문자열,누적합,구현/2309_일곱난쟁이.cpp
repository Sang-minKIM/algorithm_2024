#include <bits/stdc++.h>
using namespace std;
int a[9], target, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    sort(a, a + 9);
    target = accumulate(a, a + 9, 0) - 100;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (a[i] + a[j] == target) {
                x = i;
                y = j;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (i == x || i == y) continue;
        cout << a[i] << '\n';
    }

    return 0;
}
