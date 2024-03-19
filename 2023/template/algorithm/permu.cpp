// 순열
#include <bits/stdc++.h>
using namespace std;

int n, k, a[10];
bool visited[10];

void permu(int cnt) {
    if(cnt == k){
        for(int i = 0; i < k; i++) {
            cout <<  a[i] << " ";
        } 
        cout << '\n';
        return; 
    }
    for(int i = 1; i <=n; i++) {
       if(!visited[i]) {
            a[cnt] = i;
            visited[i] = 1;
            permu(cnt + 1);
            visited[i] = 0;
       }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    permu(0);
    
    return 0;
}

