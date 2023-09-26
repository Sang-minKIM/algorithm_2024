#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
string s;

bool cmp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        string temp = "";

        for(int j = 0; j < s.size(); j++) {
            int idx = s[j];
            if(idx >= 'a' && idx <='z') {
                if(temp.size()) v.push_back(temp);
                temp = "";
            } else {
                if(temp == "0") temp = s[j];
                else temp += s[j];

            }
        }
        if(temp.size()) v.push_back(temp);
    } 
    sort(v.begin(), v.end(), cmp);

    for(string num : v) {
        cout << num << "\n";
    }
    return 0;
}