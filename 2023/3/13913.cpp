// 숨바꼭질 4

#include<bits/stdc++.h>
using namespace std;

#define prev ddddddddd

int n, k;
int visited[200004], prev[200004];
vector<int> ret;


queue<int> q;

void bfs(int n) {
    q.push(n);
    visited[n] = 1;

    while(q.size()) {
        int here = q.front();

        if(here == k) {
            return;
        }
        q.pop();
        for(int there : {here + 1, here - 1, here * 2}) {
            if(there <= 200000 && there >=0) {
                if(visited[there] == 0) {
                    visited[there] = visited[here] + 1;
                    prev[there] = here;
                    q.push(there);
                } 
            }
        }
    }
}

int main() {
    cin >> n >> k;
    if(n == k) cout << 0 << "\n" << n << "\n";

    else {
        bfs(n);
        cout << visited[k] - 1 << "\n";
        for(int i = k; i != n; i = prev[i]) {
            ret.push_back(i);
        }
        ret.push_back(n);
        reverse(ret.begin(), ret.end());
        for(int v : ret) {
            cout << v << " ";
        }
    }

    return 0;
}