#include <bits/stdc++.h>
using namespace std;
int n, ret=-987654321;
string s;
vector<int> num;
vector<char> cha;

int calc(char oper, int a, int b) {
    if(oper == '*') return a*b;
    if(oper == '-') return a-b;
    else return a+b;
}

void dfs(int idx, int sum) {
    if(idx == num.size() - 1) {
        ret = max(ret, sum);
        return;
    }
    dfs(idx + 1, calc(cha[idx], sum, num[idx + 1]));
    int temp =  calc(cha[idx+1], num[idx+1], num[idx + 2]);
    if(idx + 2 < num.size()) dfs(idx + 2, calc(cha[idx], sum, temp));

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else cha.push_back(s[i]);
    }
    dfs(0, num[0]);

    cout << ret << "\n";

    return 0;
}