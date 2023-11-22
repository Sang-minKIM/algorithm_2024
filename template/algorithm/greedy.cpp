// 보석도둑
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m, v, n, k, ret, a, b, c;
vector<pair<ll, ll>> gold;
vector<ll> bag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        gold.push_back({a, b});
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        bag.push_back(c);
    }

    sort(gold.begin(), gold.end());
    sort(bag.begin(), bag.end());
    priority_queue<ll> pq;

    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && gold[j].first <= bag[i]) pq.push(gold[j++].second);
        if (pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';

    return 0;
}