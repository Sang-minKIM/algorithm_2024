#include <bits/stdc++.h>
using namespace std;

int n, ret = 60, a[5], t[3] = {9, 3, 1};
vector<int> v;

void go(vector<int> v, int s){
    if(*max_element(a, a + 3) <= 0){
        ret = min(ret, s);
        return;
    }
    do{
        if(s + 1 < ret){
            for(int i = 0; i < n; i++) a[v[i]] -= t[i];
            go(v, s + 1);
            for(int i = 0; i < n; i++) a[v[i]] += t[i];
        }
    } while(next_permutation(v.begin(), v.end()));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) v.push_back(i);
    go(v, 0);
    cout << ret << "\n";
    return 0;
}