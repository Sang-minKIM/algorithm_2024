#include <bits/stdc++.h>
using namespace std;
int a[26];
string inputStr, str, ans;
char oddChar;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> inputStr;
    for (char c : inputStr) {
        a[c - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (a[i] % 2) {
            if (oddChar) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
            oddChar = char('A' + i);
        }
        for (int j = 0; j < a[i] / 2; j++) {
            str += char('A' + i);
        }
    }
    ans += str;
    if (oddChar) ans += oddChar;
    reverse(str.begin(), str.end());
    ans += str;
    cout << ans;
    return 0;
}