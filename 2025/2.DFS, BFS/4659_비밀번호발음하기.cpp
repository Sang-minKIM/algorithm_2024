#include <bits/stdc++.h>
using namespace std;
#define prev pppp

string str;
char prev;
bool isM, flag = 1, mFlag;
int cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        cin >> str;
        if (str == "end") break;
        for (char c : str) {
            if (prev == c && c != 'e' && c != 'o') {
                flag = 0;
                break;
            } else {
                prev = c;
            }
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                if (isM) {
                    cnt++;
                } else {
                    cnt = 1;
                    isM = 1;
                    mFlag = 1;
                }
            } else {
                if (isM) {
                    cnt = 1;
                    isM = 0;
                } else {
                    cnt++;
                }
            }
            if (cnt >= 3) {
                flag = 0;
                break;
            }
        }
        if (mFlag == 0) {
            flag = 0;
        }
        if (flag) {
            cout << '<' << str << '>' << " is acceptable.\n";
        } else {
            cout << '<' << str << '>' << " is not acceptable.\n";
        }
        mFlag = 0;
        flag = 1;
        cnt = 0;
        isM = 0;
        prev = ' ';
    }

    return 0;
}