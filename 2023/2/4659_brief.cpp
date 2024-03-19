#include <bits/stdc++.h>
using namespace std;

string s;

bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> s) {
        if(s == "end") break;
        int ccnt = 0, vcnt = 0, prev = -1;
        bool has_vowel = false, flag = true;
        for(int idx : s) {
            if(isVowel(idx)) {
                vcnt++;
                ccnt = 0;
                has_vowel = true;
            } else {
                vcnt = 0;
                ccnt++;
            }
            if(vcnt == 3 || ccnt == 3) flag = false;
            if((prev == idx) && (idx != 'e' && idx != 'o')) {
                flag = false;
            }
            prev = idx;
        }
        if(has_vowel == false) flag = false;

        if(flag) {
            cout << "<" << s << "> is acceptable." << "\n";
        } else {
            cout << "<" << s << "> is not acceptable." << "\n";   
        }
    }
    return 0;
}