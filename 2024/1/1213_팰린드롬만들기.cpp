#include <bits/stdc++.h>
using namespace std;

string str, pre, ans;
int arr[26], cnt;
char odd;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (char c : str) {
        arr[c - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2) {
            cnt++;
            odd = i + 'A';
            arr[i]--;
        }
        if (cnt > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        for (int j = 0; j < arr[i] / 2; j++) {
            pre += i + 'A';
        }
    }
    ans = pre;
    if (odd) ans += odd;  // 이거 없으면 출력 잘나오는데도 틀렸습니다로 나옴. 조심하기
    reverse(pre.begin(), pre.end());
    ans += pre;
    cout << ans;
    return 0;
}
