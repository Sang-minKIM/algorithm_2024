#include <bits/stdc++.h>
using namespace std;

int n, num, cnt;

void dfs(int num, int five) {
    cnt += num / five;
    if (num >= five * 5) {
        dfs(num, five * 5);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num >= 5) {
            dfs(num, 5);
        }
        cout << cnt << '\n';
        cnt = 0;
    }

    return 0;
}

반복문으로 풀면 더 짧게 할 수도 있음