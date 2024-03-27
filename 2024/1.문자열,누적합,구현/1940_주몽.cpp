#include <bits/stdc++.h>
using namespace std;

int n, m, r, l, arr[15004], sum, ret;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    r = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    while (l < r) {
        sum = arr[l] + arr[r];
        if (sum == m) {
            ret++;
            l++;
            continue;
        }
        if (sum > m) {
            r--;
            continue;
        }
        l++;
    }
    cout << ret;
    return 0;
}

시간복잡도를 생각해보면 nC2는 좋은 풀이가 아니다.