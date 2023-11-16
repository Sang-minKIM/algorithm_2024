// 두 수의 합

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, l, r, x, ret;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int arr[n];
    for(int i  = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);
    l = 0; r = n-1;
    while(l < r) {
        if(arr[l] + arr[r] == x) {
            r--;
            ret++;
        } else if(arr[l] + arr[r] < x) {
            l++;
        } else if(arr[l] + arr[r] > x) {
            r--;
        }
    }

    cout << ret << '\n';
   
    return 0;
}

