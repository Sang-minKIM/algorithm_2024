#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
string s, ret;

bool cmp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void go() {
    while(true) {
        if(ret.size() && ret.front() == '0') ret.erase(ret.begin());
        else break;
    }
    if(ret.size() == 0) ret = "0";
    v.push_back(ret);
    ret = "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        ret = "";
        for(int j = 0; j < s.size(); j++) {
            if(s[j] < 65) ret += s[j];
            else if(ret.size()) go();
        }
        if(ret.size()) go();
    } 
    sort(v.begin(), v.end(), cmp);
    for(string num : v) {
        cout << num << "\n";
    }
    return 0;
}
