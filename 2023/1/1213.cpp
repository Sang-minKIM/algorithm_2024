#include <bits/stdc++.h>
using namespace std;
string input;
char mid;
vector<char> words;
int arr[26], cnt;


string solve() {
    string ret = "";
     auto pos = find(words.begin(), words.end(), mid);
    if (pos != words.end()) {
        words.erase(pos); // words 벡터에서 중간 문자를 제거합니다.
    }
    sort(words.begin(), words.end(), greater<char>());
    if (cnt == 1) ret = mid;
    for (int i = 0; i < words.size(); i += 2) {
        ret = words[i] + ret;
        if (i + 1 < words.size()) {
            ret += words[i + 1];
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;
    for(char s : input) {
        words.push_back(s);
        arr[s - 'A']++;
    }
    for(int i = 0; i<26; i++) {
        if(arr[i] % 2) {
            cnt++;
            mid = (char)(i + 'A');
        }
    }
    if(cnt > 1) {
        cout << "I'm Sorry Hansoo" << "\n";
        exit(0);
    }


    string ans = solve();
    cout << ans <<"\n";
        return 0;
}
