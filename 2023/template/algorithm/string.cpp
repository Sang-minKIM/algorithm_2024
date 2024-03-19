// 펠린드롬 만들기
#include <bits/stdc++.h>
using namespace std;

string s, ret;
int a[200], flag;
char mid;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(char c : s) a[c]++;
    for(int i = 'Z'; i >= 'A'; i--){
        if(a[i]) {
            if(a[i] % 2 == 1) {
                flag++;
                a[i]--;
                mid = char(i);
            }
            if(flag > 1) {cout << "I'm Sorry Hansoo" <<'\n'; return 0;}
            for(int j = 0; j <a[i]; j += 2) {
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    cout << ret << '\n';
    return 0;
}