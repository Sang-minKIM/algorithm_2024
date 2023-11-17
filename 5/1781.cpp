// 컵라면

#include <bits/stdc++.h>
using namespace std;
int n, due, cup, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int> , greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> due >> cup;
        v.push_back({due, cup});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }

    while(pq.size()) {
        ret+=pq.top();
        pq.pop();
    }

    cout<< ret << '\n';
     
    return 0;
}


