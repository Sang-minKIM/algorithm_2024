#include <bits/stdc++.h>
using namespace std;
int n, alpha[26];
string s, ret;


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        alpha[s[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(alpha[i] >=5) {
            ret += (i + 'a');
        }
    }
     if(ret.size()) cout << ret<< "\n";
        else cout << "PREDAJA" << "\n";

    return 0;
}