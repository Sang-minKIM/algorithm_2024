// 부등호

#include <bits/stdc++.h>
using namespace std;

int n,visited[10];
char a[10];

vector<string> v;

bool calc(char a, char b, char op) {
    if(a < b && op == '<') return true;
    if(a > b && op == '>') return true;
    return false;
}

void dfs(int depth, string s) {
    if(depth == n + 1) {
        v.push_back(s);
        return;
    }
    for(int i = 0; i < 10; i++) {
        if(visited[i]) continue;
        if(depth == 0 || calc(s[depth - 1], i + '0', a[depth - 1])) {
            visited[i] = 1;
            dfs(depth + 1, s + to_string(i));
            visited[i] = 0; 
        }
        
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, "");
    sort(v.begin(), v.end());
    cout <<v[v.size()-1]  << '\n' << v[0] <<'\n';

    return 0;
}