#include <bits/stdc++.h>
using namespace std;

int n, k, temp, maxT = -1e9, arr[100004];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }

    for (int i = 0; i <= n - k; i++) {
        maxT = max(maxT, arr[i + k] - arr[i]);
    }
    cout << maxT;
    return 0;
}

누적합 풀 때 처음을 비워야함 = > 처음을 빼먹을 수 있음