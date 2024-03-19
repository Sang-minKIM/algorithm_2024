// 멀티탭 스케줄링

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int a[104], visited[104], n, k, cnt;

vector<int> plug;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        if(!visited[a[i]]){
            if(plug.size() == n){
                int last_idx = 0, pos;
                for(int code : plug){
                    int code_idx = INF;
                    for(int j = i + 1; j < k; j++){
                        if(code == a[j]){
                            code_idx = j; break;
                        }
                    }
                    if(last_idx < code_idx){
                        last_idx = code_idx;
                        pos = code;
                    }
                }
                visited[pos] = 0;
                cnt++;
                plug.erase(find(plug.begin(), plug.end(), pos));
            }
            plug.push_back(a[i]); visited[a[i]] = 1;
        }
    }
        cout << cnt << "\n";
    return 0;
}

