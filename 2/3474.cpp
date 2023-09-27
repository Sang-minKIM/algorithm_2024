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
        int ret2= 0, ret5 =0; 
        for(int two = 2; two <= a; two*=2 ){
            ret2 += a / two;
        }
        for(int five = 5; five <= a; five*=5) {
            ret5 += a / five;
        }
        cout << min(ret2, ret5) << "\n";
    }

    return 0;
}