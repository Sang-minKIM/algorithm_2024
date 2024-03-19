//폭발 문자열

#include <bits/stdc++.h>
using namespace std;
string s, ex, ret = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> ex;

    int sl = s.size();
    int el = ex.size();
    for(int i = 0; i < sl; i++) {
        ret += s[i];
        while(ret.size() >= el && ret.substr(ret.size() - el, el) == ex) {
            ret.erase(ret.size() - el, el);
        }
    }
    
    if(ret.size()) cout << ret << '\n';
    else cout << "FRULA" << '\n';

     
    return 0;
}

