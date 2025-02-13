#include <bits/stdc++.h>
using namespace std;
#define prev aaa
string t, prev;
int n, k, a, b, asum, bsum;

int getSec(string s) { return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str()); }

void print(int sec) {
    string m = "00" + to_string(sec / 60);
    string s = "00" + to_string(sec % 60);
    cout << m.substr(m.size() - 2, 2) << ':' << s.substr(s.size() - 2, 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> t;
        if (a > b)
            asum += getSec(t) - getSec(prev);
        else if (a < b)
            bsum += getSec(t) - getSec(prev);
        k == 1 ? a++ : b++;
        prev = t;
    }
    if (a > b)
        asum += getSec("48:00") - getSec(prev);
    else if (a < b)
        bsum += getSec("48:00") - getSec(prev);
    print(asum);
    cout << '\n';
    print(bsum);

    return 0;
}