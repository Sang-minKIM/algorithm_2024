#include <bits/stdc++.h>
using namespace std;
int n, m, ret, temp;
vector<int> input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        input.push_back(temp);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = input[i] + input[j];
            if(sum == m) ret++;
        }
    }
    cout << ret <<"\n";
    return 0;
}
