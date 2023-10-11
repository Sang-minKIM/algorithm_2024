#include <bits/stdc++.h>
using namespace std;
int temp, root, cnt, n, k;

vector<int> arr[51];

int dfs(int here) {
    int ret = 0;
    int child = 0;
    for(int there : arr[here]) {
        if(there == k) continue;
        ret += dfs(there);
        child++;
    }
    if(child == 0) return 1; 
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin>> temp;
        if(temp == -1) root = i;   
        else arr[temp].push_back(i);
    }
    cin >> k;
    if(root != k) cnt = dfs(root);
    cout << cnt <<"\n";
    return 0;
}