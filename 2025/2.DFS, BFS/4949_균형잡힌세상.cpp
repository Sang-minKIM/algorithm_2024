#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        getline(cin, s);

        if (s == ".") break;
        stack<char> stk;
        bool flag = true;
        for (char c : s) {
            if (c == '[' || c == '(')
                stk.push(c);
            else if (c == ')') {
                if (stk.size() && stk.top() == '(') {
                    stk.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if (c == ']') {
                if (stk.size() && stk.top() == '[') {
                    stk.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (stk.size() != 0 || flag == false)
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';
    }
    return 0;
}