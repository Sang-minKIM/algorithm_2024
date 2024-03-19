#include <bits/stdc++.h>
using namespace std;
#define prev dddddd

string t, prev;
int A, B, n, team, asum, bsum;

int getSec(string t) {
    return atoi(t.substr(0, 2).c_str()) * 60 + atoi(t.substr(3, 2).c_str());
}

void calc(int &sum, string s) {
    sum += (getSec(s) - getSec(prev));
}

string print(int sec) {
    string m = "00" + to_string(sec / 60);
    string s = "00" + to_string(sec % 60);
    return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> team >> t;
        if(A > B) calc(asum, t);
        else if(A < B) calc(bsum, t);
        team == 1 ? A++: B++;
        prev = t;
    }
    if(A > B) calc(asum, "48:00");
    else if(A < B) calc(bsum, "48:00");
    cout << print(asum) << "\n" << print(bsum) << "\n";
    return 0;
}