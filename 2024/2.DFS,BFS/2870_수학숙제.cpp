#include <bits/stdc++.h>
using namespace std;

string s, ret;
int n;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

void go() {
    while (true) {
        if (ret.size() && ret.front() == '0')
            ret.erase(ret.begin());
        else
            break;
    }
    if (ret.size() == 0) ret = "0";
    v.push_back(ret);
    ret = "";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> s;
        ret = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < 97) {
                ret += s[i];
            } else if (ret.size()) {
                go();
            }
        }
        if (ret.size()) go();
    }

    sort(v.begin(), v.end(), cmp);
    for (auto ans : v) {
        cout << ans << '\n';
    }

    return 0;
}

문자열은 확실히 어렵다.substr을 써서 해보려했는데 오히려 하나씩 더하는게 더 쉬웠음