#include <bits/stdc++.h>
using namespace std;
int m;
string str, ret;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return true;
    }
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str;
        for (char c : str) {
            if (c >= '0' && c <= '9') {
                ret += c;
            } else {
                if (ret.size()) {
                    while (ret.size() > 1 && ret[0] == '0') {
                        ret = ret.substr(1, ret.size() - 1);
                    }
                    v.push_back(ret);
                    ret = "";
                }
            }
        }
        if (ret.size()) {
            while (ret.size() > 1 && ret[0] == '0') {
                ret = ret.substr(1, ret.size() - 1);
            }
            v.push_back(ret);
            ret = "";
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (auto s : v) {
        cout << s << '\n';
    }
    return 0;
}