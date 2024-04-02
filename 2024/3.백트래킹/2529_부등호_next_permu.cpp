#include <bits/stdc++.h>

using namespace std;
char a[10];
int n, num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<string> v;

bool check(int c, int b, int k) {
    if (a[k] == '<') {
        return c < b;
    } else {
        return c > b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    do {
        string s = to_string(num[0]);

        for (int k = 1; k < n + 1; k++) {
            if (!check(num[k - 1], num[k], k - 1)) {
                break;
            }
            s += to_string(num[k]);
        }
        if (s.size() == n + 1) {
            v.push_back(s);
        }
    } while (next_permutation(num, num + 10));

    sort(v.begin(), v.end());

    cout << v[v.size() - 1] << '\n' << v[0];

    return 0;
}