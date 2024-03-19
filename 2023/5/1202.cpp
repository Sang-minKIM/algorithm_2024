// 보석도둑

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m, v, c, n, k, ret;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    vector<pair<ll, ll>> gold(n);
    vector<ll> bag(k);  

    for(int i = 0; i < n; i++) {
        cin >> gold[i].first >> gold[i].second;
    }
    for(int i = 0; i < k; i++) {
        cin >> bag[i];
    }
    
    sort(gold.begin(), gold.end());
    sort(bag.begin(), bag.end());
    priority_queue<ll> pq;

    int j = 0;
    for(int i = 0; i < k; i++) {
        while(j < n && gold[j].first <= bag[i]) pq.push(gold[j++].second);
        if(pq.size()) {
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << '\n';

    return 0;
}