#include <bits/stdc++.h>
using namespace std;
#define y1 xoxoxoxo
int n;
string ret;
char a[65][65];

string go(int y1, int x1, int y2, int x2) {
    string ret = "";
    if (y1 == y2 - 1 && x1 == x2 - 1) {
        return ret + a[y1][x1];
    }

    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            if (a[y1][x1] != a[i][j]) {
                ret += '(';
                int my = (y1 + y2) / 2;
                int mx = (x1 + x2) / 2;
                ret += go(y1, x1, my, mx);
                ret += go(y1, mx, my, x2);
                ret += go(my, x1, y2, mx);
                ret += go(my, mx, y2, x2);
                ret += ')';
                return ret;
            }
        }
    }
    return ret + a[y1][x1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[j];
        }
    }
    ret += go(0, 0, n, n);
    cout << ret;
    return 0;
}