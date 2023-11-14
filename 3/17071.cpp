//숨바꼭질 5
#include<bits/stdc++.h>
using namespace std;

int n, k, turn = 1;
const int MAX = 500000;
int visited[2][MAX + 4];
bool flag = 0;

queue<int> q;

void bfs(int n) {
    q.push(n);
    visited[0][n] = 1;
    while(q.size()) {
        k += turn;
        if(k > MAX) return;
        if(visited[turn % 2][k]) {
            flag = true;
            return;
        }
        int qSize = q.size();
        for(int i = 0; i < qSize; i++) {
            int here = q.front();
            q.pop();
            for(int there : {here + 1, here - 1, here * 2}) {
                if(there > MAX || there < 0 || visited[turn % 2][there]) continue;
                visited[turn % 2][there] = visited[(turn +1) % 2][here] + 1;
                if(there == k) {
                    flag = true;
                    return;
                }
                q.push(there);
            }
        }
       turn++;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    if(n == k){
        cout << 0 << "\n";
        return 0;
    } 

    bfs(n);
    if(!flag) cout << -1 << "\n";
    else cout << turn << "\n";

    return 0;
}