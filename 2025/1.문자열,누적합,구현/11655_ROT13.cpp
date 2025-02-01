#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 65 && s[i] < 65 + 26) {  // 대문자
            if (s[i] - 'A' < 13) {
                s[i] = char(s[i] + 13);
            } else {
                s[i] = char(s[i] - 13);
            }
        } else if (s[i] >= 97 && s[i] < 97 + 26) {  // 소문자
            if (s[i] - 'a' < 13) {
                s[i] = char(s[i] + 13);
            } else {
                s[i] = char(s[i] - 13);
            }
        }
    }
    cout << s;
    return 0;
}