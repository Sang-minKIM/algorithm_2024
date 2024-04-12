#include <bits/stdc++.h>
using namespace std;

void 비트끄기() {
    int S = 18;  // 10010
    int idx = 1;
    S &= ~(1 << idx);
    cout << S << '\n';  // 16
}

void 비트XOR() {
    int S = 18;
    int idx = 1;
    S ^= (1 << idx);
    cout << S << '\n';  // 16
}

void 최하위켜진비트() {
    int S = 18;
    int idx = (S & -S);
    cout << idx << '\n';
}

void 모든비트켜기() {
    int n = 4;
    cout << (1 << n) - 1 << '\n';
}

void 비트하나켜기() {
    int S = 18;
    int idx = 0;
    S |= (1 << idx);
    cout << S << '\n';
}

void 켜진비트확인() {
    int S = 18;
    int idx = 0;
    if (S & (1 << idx)) {
        cout << "해당 idx : " << idx << "가 켜져있습니다.\n";
    } else {
        cout << "해당 idx : " << idx << "가 꺼져있습니다.\n";
    }
}

void 비트마스킹() {
    const int n = 4;
    string a[n] = {"사과", "딸기", "포도", "배"};
    for (int i = 0; i < (1 << n); i++) {
        string ret = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ret += (a[j] + " ");
            }
        }
        cout << ret << '\n';
    }
}

const int n = 4;
string a[n] = {"사과", "딸기", "포도", "배"};

void go(int num) {
    string ret = "";
    for (int i = 0; i < n; i++) {
        if (num & (1 << i)) ret += a[i] + " ";
    }
    cout << ret << '\n';
    return;
}

void 매개변수전달() {
    for (int i = 1; i < n; i++) {
        go(1 | (1 << i));
    }
    return;
}

int main() {
    비트끄기();
    비트XOR();
    최하위켜진비트();
    모든비트켜기();
    비트하나켜기();
    비트마스킹();
    매개변수전달();
    return 0;
}
