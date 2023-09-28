#include <bits/stdc++.h>
using namespace std;

int n;
string input;
vector<string> ret;

bool check(string input) {
     stack<char> vps;
        for(int j= 0; j < input.size(); j++) {
            if(input[j] == '(' || input[j] == '[') {
                vps.push(input[j]);
            }else if(input[j] == ')'){
                if(vps.size()) {
                   char topc = vps.top();
                   if(topc == '[' ) return false;
                   if(topc == '(' ) vps.pop();
                } else {
                    return false;
                }
            } else if(input[j] == ']'){
                if(vps.size()) {
                   char topc = vps.top();
                   if(topc == '[' ) vps.pop();
                   if(topc == '(' ) return false;
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
   while(true) {
        getline(cin, input);
        if(input == ".") break;
        if(check(input)) ret.push_back("yes");
        else ret.push_back("no");
        
        // if(check(input)) cout<< "yes" <<"\n";
        // else cout<< "no" << "\n";
    }
for(string s : ret ){
            cout << s << "\n";
        }
    return 0;
}