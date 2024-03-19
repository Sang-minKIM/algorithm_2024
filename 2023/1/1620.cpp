#include <bits/stdc++.h>
using namespace std;
int m, n;
string temp;
map<string,int> smap;
map<int, string> nmap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    for(int i = 1; i <=m; i++) {
        cin >> temp;
        smap.insert({temp, i});
        nmap.insert({i, temp});
    }
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(atoi(temp.c_str())) cout << nmap[stoi(temp)] << "\n";
        else cout << smap[temp] << "\n";
    }
    return 0;
}