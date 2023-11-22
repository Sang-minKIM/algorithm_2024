// 분할정복

#include <bits/stdc++.h>
using namespace std;
int n;
char a[65][65];

string quard(int y, int x, int size) {
    if (size == 1) return string(1, a[y][x]);
    char c = a[y][x];
    string ret = "";
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (a[i][j] != c) {
                ret = "(";
                ret += quard(y, x, size / 2);
                ret += quard(y, x + size / 2, size / 2);
                ret += quard(y + size / 2, x, size / 2);
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, a[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> a[y][x];
        }
    }

    cout << quard(0, 0, n) << "\n";
    return 0;
}
