#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;

ll go(ll n) {
    if (n == 1) return a % c;
    ll ret = go(n / 2);
    ret = (ret * ret) % c;
    if (n % 2) ret = (ret * a) % c;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    cout << go(b);
    return 0;
}

거듭 제곱 분할을 생각하는 것이 중요했음, 숫자가 커지면 모듈러 연산 해주기