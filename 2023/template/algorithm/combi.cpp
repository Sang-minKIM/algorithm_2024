// 조합
#include <bits/stdc++.h>
using namespace std;

int n, k, a[10];

void combi(int cnt, int start) {
    if (cnt == k) {
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        a[cnt] = i;
        combi(cnt + 1, i + 1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    combi(0, 1);
    return 0;
}

//  인덱스 뽑는 조합
#include <bits/stdc++.h>
using namespace std;

int n, k, a[10];

void combi(int cnt, int start) {
    if (cnt == k) {
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        a[cnt] = i;
        combi(cnt + 1, i + 1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    // cout << n << k;
    combi(0, 0);
    return 0;
}
