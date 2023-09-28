#include <bits/stdc++.h>
using namespace std;

int n;
string input;

bool check(string input) {
     stack<char> vps;
        for(int j= 0; j < input.size(); j++) {
            if(input[j] == '(') {
                vps.push(input[j]);
            }
            else{
                if(vps.size()) {
                   vps.pop();
                } else {
                    return false;
                }
            }
        }
        return vps.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
   for(int i = 0; i < n; i++) {
        cin >> input;
       
        if(check(input)) cout<< "YES" <<"\n";
        else cout<< "NO" << "\n";
    }

    return 0;
}