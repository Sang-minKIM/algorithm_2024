// 칠무해

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
double score;
priority_queue<double> pq;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> score;
        pq.push(score);
        if(pq.size() > 7) pq.pop();
    }
    while(pq.size()){
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for(double s : v) {
        cout.precision(3);
        cout << fixed;
        cout << s << '\n';
    }

    return 0;
}