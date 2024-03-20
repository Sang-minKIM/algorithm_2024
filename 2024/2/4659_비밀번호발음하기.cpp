#include <bits/stdc++.h>
using namespace std;

string str, mo = "aeiou";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        cin >> str;
        if (str == "end") break;
        char pre = 'A';
        int mCnt = 0, jCnt = 0, flag = 0;
        for (char c : str) {
            if (mo.find(c) != string::npos) {
                flag = 1;
                mCnt++;
                jCnt = 0;
            } else {
                jCnt++;
                mCnt = 0;
            }
            if (mCnt > 2 || jCnt > 2) {
                flag = 0;
                break;
            }
            if (pre != 'A' && pre == c && c != 'e' && c != 'o') {
                flag = 0;
                break;
            }
            pre = c;
        }
        if (flag == 0)
            cout << "<" << str << "> is not acceptable." << '\n';
        else
            cout << "<" << str << "> is acceptable." << '\n';
    }

    return 0;
}