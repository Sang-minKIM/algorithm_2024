//그룹단어 체커
#include <bits/stdc++.h>
using namespace std;

string s;

int ret, n, a[26];

bool check(string s) {
    fill(a, a+26, 0);
    char curr;
    for(int i = 0; i < s.size(); i++) {
        if(curr != s[i] && a[s[i] - 'a']) return false;
        a[s[i] - 'a']++;
        curr = s[i];
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(check(s)) ret++;
    }
    
    cout << ret << '\n';
    return 0;
}