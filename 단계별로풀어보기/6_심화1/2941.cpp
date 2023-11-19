// 크로아티아 알파벳
#include <bits/stdc++.h>
using namespace std;

string s;
string a[7] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};

int cnt, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    while(cnt < s.size()) {
        if(find(a, a + 7, s.substr(cnt, 2)) == a + 7) {
            if(s.substr(cnt, 3) == "dz=") {
                ret++;
                cnt += 3;
            } else {
                ret++;
                cnt++;
            }
        } else  {
            ret++;
            cnt += 2;
        }
    }
    
    cout << ret << '\n';
    return 0;
}