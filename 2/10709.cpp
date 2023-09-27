#include <bits/stdc++.h>
using namespace std;
string a[104][104], s;
int h, w;

void dfs(int y, int x, int depth) {
    a[y][x] = to_string(depth);
    if(x + 1 >= 0 && x + 1 < w && a[y][x + 1] == ".") dfs(y, x+1, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    for(int y = 0; y < h; y++) {
         cin >> s;
        for(int x = 0; x < w; x++) {
           a[y][x] = s[x];
        }
    }
    
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            if(a[y][x] == "c") dfs(y, x, 0);
            else if(a[y][x] == ".") a[y][x] = "-1";
        }
    }
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            cout << a[y][x] << " ";        
        }
        cout << "\n";
    }
    return 0;
}
