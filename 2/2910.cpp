#include <bits/stdc++.h>
using namespace std;

int n, c, temp;
bool flag = false;
vector<pair<int, int>> v;
map<int, int> mp;


bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return mp[a.first] < mp[b.first];
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(v.size()) {
            for(int j = 0; j<v.size(); j++) {
                if(v[j].first == temp) {
                    v[j].second++;
                    flag = true;
                    break;
                }
                
            }
            if(flag) {
                flag = false;
            } else {
                v.push_back({temp, 1});
                mp[temp] = i;
            }
        } else {
            mp[temp] = i;
            v.push_back({temp, 1});
        }
       
    }
    sort(v.begin(), v.end(), compare);
    for(auto p : v) {
        for(int i = 0; i < p.second; i++) {
            cout<< p.first << " ";
        }
    }
    cout << "\n";
    return 0;
}