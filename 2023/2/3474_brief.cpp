#include <bits/stdc++.h>
using namespace std;

int n, a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        int ret5 =0; 
        for(int five = 5; five <= a; five*=5) {
            ret5 += a / five;
        }
        cout <<  ret5 << "\n";
    }

    return 0;
}