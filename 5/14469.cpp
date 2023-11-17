// 소가 길을 건너는 이유 3

#include <bits/stdc++.h>
using namespace std;
int n, a, b, t;
vector<pair<int, int>> v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        if(t > v[i].first) {
            t += v[i].second;
        } else {
            t = v[i].first + v[i].second;
        }
    }

    cout<< t << '\n';
     
    return 0;
}

