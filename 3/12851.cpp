// 숨바꼭질 2
#include<bits/stdc++.h>
using namespace std;

int n, k;
int visited[100004][2];
queue<int> q;

void bfs(int n) {
    q.push(n);
    visited[n][0] = 1;
    visited[n][1] = 1;
    while(q.size()) {
        int here = q.front();
        q.pop();
        for(int there : {here + 1, here - 1, here * 2}) {
            if(there <= 100000 && there >=0) {
                if(visited[there][0] == 0) {
                    visited[there][0] = visited[here][0] + 1;
                    visited[there][1] = visited[here][1];
                    q.push(there);
                } else if(visited[there][0] == visited[here][0] + 1) {
                    visited[there][1] += visited[here][1];
                }
            }
        }
    }
}

int main() {
    cin >> n >> k;
    if(n == k) cout << 0 << "\n" << 1 << "\n";
    else if(n > k) cout << n-k << "\n" << 1 << "\n";
    else {
        bfs(n);
        cout << visited[k][0] - 1 << "\n" << visited[k][1] << "\n";
    }

    return 0;
}