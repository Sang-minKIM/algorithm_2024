#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, key, value;
map<ll, ll> mp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    queue<pair<ll, ll>> q;
    q.push({n, 0});
    while (q.size()) {
        tie(key, value) = q.front();
        q.pop();
        mp[key] = value;
        if (key == 1) {
            break;
        }

        if (key % 3 == 0 && mp[key / 3] == 0) {
            mp[key / 3] = value + 1;
            q.push({key / 3, value + 1});
        }
        if (key % 2 == 0 && mp[key / 2] == 0) {
            mp[key / 2] = value + 1;
            q.push({key / 2, value + 1});
        }
        if (mp[key - 1] == 0) {
            mp[key - 1] = value + 1;
            q.push({key - 1, value + 1});
        }
    }

    cout << mp[1];

    return 0;
}

bfs로 해야 시간 초과 안나고, map에 방문 기록 하는 것도 방문하기 전에 해야 반복 조금이라도 줄일 수 있어서 시간 초과 안남