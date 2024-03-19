//순회공연

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d, p, ret;
vector<pair<int, int>> v;



// struct Compare {
//     bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
//         if(a.second == b.second) {
//             return a.first < b.first;
//         }
//         return a.second > b.second;
//     }
// };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    if(n == 0) {
        cout << 0 << '\n';
        return 0;
    } 
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }

    while(pq.size()) {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << '\n';

    return 0;
}

