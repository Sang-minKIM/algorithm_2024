// List of Unique Numbers

#include <bits/stdc++.h>
using namespace std;

long long visited[100004], a[100004], n, r, l, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i =0; i< n; i++ ){
        cin >> a[i];
    }

    while(r < n) {
        if(visited[a[r]] == 0) {
            visited[a[r]] = 1;
            r++;
        } else {
            ret += r - l;
            visited[a[l]] = 0;
            l++;
        }
    }
    ret += (r -l) * (r - l + 1) / 2;

    cout << ret << '\n';
    return 0;
}

