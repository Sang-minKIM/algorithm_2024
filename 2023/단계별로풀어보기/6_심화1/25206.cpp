// 너의 평점은
#include <bits/stdc++.h>
using namespace std;

string sub, grade;

double ret, num, sum, total;

map<string, double> mp;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mp["A+"] = 4.5;
    mp["A0"] = 4.0;
    mp["B+"] = 3.5;
    mp["B0"] = 3.0;
    mp["C+"] = 2.5;
    mp["C0"] = 2.0;
    mp["D+"] = 1.5;
    mp["D0"] = 1.0;
    mp["F"] = 0.0;
    for(int i = 0; i < 20; i++) {
        cin >> sub >> num >> grade;
        if(grade == "P") continue;
        sum += num * mp[grade];
        total += num;
    }
    cout << sum / total << '\n';
  



    return 0;
}