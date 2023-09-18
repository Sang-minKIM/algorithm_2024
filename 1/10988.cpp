#include <bits/stdc++.h>
using namespace std;

string word, temp;

int main() {
    cin >> word;
    temp = word;
    reverse(word.begin(), word.end());
    cout << (int)(word == temp) << "\n";
    return 0;
}