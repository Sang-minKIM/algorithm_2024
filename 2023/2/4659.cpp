#include <bits/stdc++.h>
using namespace std;
string vowel = "aeiou", s;

bool hasVowel(string s) {
    bool ret = false;
        for(int i = 0; i < 5; i++) {
            if(s.find(vowel[i]) != string::npos){
                ret = true;
            }
        }
    return ret;
}

bool isThree(string s) {
    bool prev = false, curr = false;
    int cnt = 1;
    for(int i = 0; i < s.size(); i++) {
        if(i == 0) {
            prev = vowel.find(s[i]) != string::npos;
            continue;
        }
        curr = vowel.find(s[i]) != string::npos;
        if(prev == curr) {
            cnt++;
        } else {
            cnt = 1;
        }
        prev = curr;
        if(cnt >= 3) return false;
    }
    return true;
}

bool isSame(string s) {
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != 'e' && s[i] !='o') {
            if(s[i] == s[i-1]) return false;
        }
    } 
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> s) {
        if(s == "end") break;
        if(hasVowel(s) && isThree(s) && isSame(s) ) {
            cout << "<" << s << "> is acceptable." << "\n";
        } else {
            cout << "<" << s << "> is not acceptable." << "\n";   
        }
    }
    return 0;
}