#include <bits/stdc++.h>
using namespace std;

int arr[9], sum = 0;
vector<int> v;
pair<int, int> ret;

void combi() {
    for(int i = 0; i < 9; i++) {
        for(int j=0; j< i; j++) {
            if(sum - arr[i] - arr[j] == 100) {
                ret= {i, j};
                return;
            }
        }
    }
}

int main() {
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    combi();
    for(int i=0; i<9; i++) {
        if(i == ret.first || i == ret.second) continue;
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    return 0;
}
