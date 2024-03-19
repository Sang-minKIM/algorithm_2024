// 색종이

#include <bits/stdc++.h>
using namespace std;

int n, sx, sy, a[104][104], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;   
    for(int i = 0; i < n; i++) {
        cin >> sx >> sy;
        for(int y = sy; y< sy + 10; y++) {
            for(int x = sx; x < sx + 10; x++) {
                a[y][x] = 1;
            }
        }
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(a[i][j]) ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}