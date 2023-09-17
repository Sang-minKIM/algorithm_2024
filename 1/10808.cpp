#include <bits/stdc++.h>
using namespace std;
int a[26]; // 전역변수로 선언하면 0으로 초기화됨
string s;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        a[s[i] - 97]++;
    }
   
   for(int ret : a) {
    cout << ret << " ";
   }
    return 0;
}