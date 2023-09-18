#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    getline(cin, s);
    for(int i = 0; i<s.size(); i++) {
          if(s[i] < 91 && s[i] >= 65) {
            if(s[i] + 13 < 91) {
                s[i] = s[i]+13;
            } else {
                s[i] = s[i] -13;
            }
        }
        if(s[i] < 123 && s[i] >= 97) {
            if(s[i] + 13 < 123) {
              s[i] = s[i]+13;
            } else {
                s[i] = s[i] -13;
            }
        }
    }    
    cout << s << "\n";
    return 0;
}