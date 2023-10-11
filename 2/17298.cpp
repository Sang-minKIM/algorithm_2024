#include <bits/stdc++.h>
using namespace std;
int n, arr[1000004], ret[1000004];
stack<int> stk;

void pushIn(int i) {
    while(stk.size()) {
        if(stk.top() <= i) {
            stk.pop();
        } else break;
    }
    stk.push(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ret[n-1] = -1;
    stk.push(arr[n-1]);
    for(int i = n - 1; i > 0; i--) {
        if(arr[i - 1] < arr[i]) {
            pushIn(arr[i]);
            ret[i-1] = arr[i];
        } else {
            while(stk.size()){
                if(stk.top() <= arr[i-1]) {
                    stk.pop();
                } else break;
            }
            if(stk.size()) ret[i-1] = stk.top();
            else {
                ret[i-1] = -1;
                stk.push(arr[i-1]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }
    cout << "\n";
    return 0;
}