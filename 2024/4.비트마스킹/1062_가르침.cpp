#include <bits/stdc++.h>
using namespace std;
int n, k, word[51], ret;
string str;

int check(int mark) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (word[i] && (word[i] & mark) == word[i]) cnt++;
    }
    return cnt;
}

void go(int idx, int m, int mark) {
    if (m == k) {
        ret = max(ret, check(mark));
        return;
    }
    if (idx == 26) return;
    go(idx + 1, m + 1, mark | (1 << idx));
    if (idx != ('a' - 'a') && idx != ('c' - 'a') && idx != ('n' - 'a') && idx != ('t' - 'a') && idx != ('i' - 'a')) go(idx + 1, m, mark);
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (char c : str) {
            word[i] |= (1 << (c - 'a'));
        }
    }
    go(0, 0, 0);
    cout << ret;

    return 0;
}