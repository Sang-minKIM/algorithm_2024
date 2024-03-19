#include <bits/stdc++.h>
using namespace std;
int n, arr[1000004], ret[1000004];
stack<int> stk;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        while(stk.size() && arr[stk.top()] < arr[i]) {
            ret[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }
    cout << "\n";
    return 0;
}