#include <bits/stdc++.h>
using namespace std;
int temp, root, cnt, n, k;

vector<int> arr[51];

void dfs(int x) {
    if(arr[x].size()) {
        for(int i = 0; i < arr[x].size(); i++) {
            if(arr[x][i] == k) {
                arr[x].erase(arr[x].begin() + i);
                i--;
            }
        }
    }

    if(arr[x].size() == 0) {
        cnt++;
        return;
    } else {
        for(int next : arr[x]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin>> temp;
        if(temp == -1) {
            root = i;
            continue;
        }    
        arr[temp].push_back(i);
    }
    cin >> k;
    if(root != k) dfs(root);
    cout << cnt <<"\n";
    return 0;
}