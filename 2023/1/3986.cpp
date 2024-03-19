#include <bits/stdc++.h>
using namespace std;
string input;
int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
         cin >> input;
          stack<char> stk;
        for(char c : input) {
            if(stk.size() && stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        if(stk.size() == 0) ret++;
    }
    cout << ret << "\n";
    return 0;
}
