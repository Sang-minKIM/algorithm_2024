// 괄호의 값

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n = 1, ret;
stack<int> stk;
bool flag = true;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(stk.size() == 0) {
            if(s[i] == ')' || s[i] == ']') {
                cout<< 0 << '\n';
                return 0;
            } 
        }
        if(s[i] == '(') {
            n *= 2;
            flag = 1;
            stk.push(2);
        } else if(s[i] == '[') {
            n *= 3;
            flag = 1;
            stk.push(3);
        } else if(s[i] == ')') {
            if(stk.top() == 2) {
                if(flag) ret += n;
                n /= 2;
                flag = false;
                stk.pop();
            } else {
                cout<< 0 << '\n';
                return 0;
            }
        } else if(s[i] == ']') {
            if(stk.top() == 3) {
                if(flag) ret += n;
                n /= 3;
                stk.pop();
                flag = false;

            } else {
                cout<< 0 << '\n';
                return 0;
            }
        }
    }
    if(stk.size()){
        cout << 0 <<'\n';
        return 0;
    }
   
    cout << ret <<"\n";


    return 0;
}

