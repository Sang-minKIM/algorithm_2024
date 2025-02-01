#include <bits/stdc++.h>
using namespace std;
int a[9], target, x, y, b[10];

void combi(int cnt, int start) {
    if (cnt == 2) {
        int temp = 0;
        for (int i = 0; i < 2; i++) {
            temp += a[b[i]];
        }
        if (temp == target) {
            x = a[b[0]];
            y = a[b[1]];
        }
    }
    for (int i = start; i < 9; i++) {
        b[cnt] = i;
        combi(cnt + 1, i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }
    sort(a, a + 9);
    target = accumulate(a, a + 9, 0) - 100;
    combi(0, 0);
    for (int i = 0; i < 9; i++) {
        if (a[i] == x || a[i] == y) continue;
        cout << a[i] << '\n';
    }

    return 0;
}
